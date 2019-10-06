li = [1]
for a in range(14):
	z = a + 1
	s = 0
	for b in range(z):
		s += li[b]*li[b]
	li.append(s)

for a in range(14):
	print(li[a])