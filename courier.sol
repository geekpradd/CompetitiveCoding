pragma solidity^0.5.0;

contract Courier {
    enum PackageStatus {
        inTransit,
        received,
        cancelled,
        arrived,
        booked,
    };
    
    struct Package {
        uint id;
        uint weight;
        address sender;
        PackageStatus status;
        address receiver;
    }
    constant uint MULTIPLIER = 1;
    mapping (uint => address) public packageCourierId;
    mapping (address => uint) public pendingDeliveryCharge;
    Package[] private _packages;
    event PackageBooked(uint id, address sender, address receiver, uint weight);
    event PackagePicked(uint id, address courier, address sender, address receiver);
    event PackageArrived(uint id, address courier, address sender, address receiver);
    event PackageCancelled(uint id, address courier, address sender, address receiver);
    
    function addPackage(uint memory _weight, address memory receiver) public payable returns (uint){
        uint id = _packages.length;
        _packages.push(Package({
            id: id,
            weight: _weight,
            seller: msg.sender,
            status: PackageStatus.booked
        }));
        
        require(msg.value == _weight*MULTIPLIER, "Incorrect amount");
        
        emit PackageBooked(id, msg.sender, receiver, _weight);
        pendingDeliveryCharge[msg.sender] += msg.value;
        
        return id;
        
    }
    
    function pickPackage(uint _id){
        Package storage currentPackage = _packages[_id];
        require(currentPackage.status == PackageStatus.booked, "Package is already dispatched");
        currentPackage.status = PackageStatus.inTransit;
        
        packageCourierId[_id] = msg.sender;

        emit PackagePicked(_id, msg.sender);
    
    }
    
    function arrivedPackage(uint _id){
        // this function will be called by the courier
        
        Package storage currentPackage = _packages[_id];
        currentPackage.status = PackageStatus.arrived;
        
        emit PackageArrived(_id, msg.sender, currentPackage.sender, currentPackage.receiver);
    }
    
    function receivedPackage(uint _id) returns (bool){
        // this function will be called by the receiver
        
        
        Package storage currentPackage = _packages[_id];
        
        require(currentPackage.receiver == msg.sender, "Package arrived at wrong receiver");
        currentPackage.status = PackageStatus.received;
        uint deliveryCharge = currentPackage.weight*MULTIPLIER;
        address courier = packageCourierId[_id];

        
        if(courier.send(deliveryCharge)){
            pendingDeliveryCharge[currentPackage.sender] -= deliveryCharge;
            emit PackageReceived(_id, currentPackage.sender, currentPackage.receiver);
            return true;
        }
        else {
            return false;
        }
    }
    
    function cancelPackage(uint _id) returns (bool){
        Package storage currentPackage = _packages[_id];
        require(msg.sender == currentPackage.sender && (currentPackage.status == PackageStatus.inTransit || currentPackage.status == PackageStatus.booked), "You do not have authorization to cancel package");
        uint deliveryCharge = currentPackage.weight*MULTIPLIER;
        address courier = packageCourierId[_id];
        
        
        if (currentPackage.status == inTransit){
            if (courier.send(deliveryCharge)){
                currentPackage.status = PackageStatus.cancelled;
                pendingDeliveryCharge[currentPackage.sender] -= deliveryCharge;
                emit PackageCancelled(_id, courier, currentPackage.sender, currentPackage.receiver);
                return true;
                
            }
            else {
                return false;
            }
            
        }
        
        currentPackage.status = PackageStatus.cancelled;
        return true;
    }
    
    
    
}