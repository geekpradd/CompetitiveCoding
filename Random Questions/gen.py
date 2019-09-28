from random import randint

nl = 24345
nr = 35435
sl = "4"
sr = "6"

for a in range(nl-1):
	current = str(randint(0, 9))
	sl += current

for a in range(nr-1):
	current = str(randint(0, 9))
	sr += current

with open("in.txt", "w") as f:
	f.write("1 \n")
	f.write(str(nl) + " " + sl + "\n")
	f.write(str(nr) + " " + sr + "\n")