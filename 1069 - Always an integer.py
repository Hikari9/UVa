# UVa 1069 - Always an integer
import parser
import re

r = re.compile(r'n\^([0-9]+)')
u = re.compile(r'([0-9]+)n')

def mp(b, e, m):
	b %= m
	a = 1
	while e:
		if e & 1: a = a * b % m 
		e >>= 1 
		b = b * b % m 
	return a

tc = 0
while True:
	s = str(input()).strip()
	if s == '.': break 
	ok = True 
	try:
		m = int(s[s.rfind('/') + 1:])
		s = r.sub(r'mp(n,\1,m)', u.sub(r'\1%m*n', s.replace('/', '%').replace(' ', '')))
		for n in range(101):
			if eval(s) != 0:
				ok = False 
				break
	except:
		ok = False
	tc += 1 
	print('Case %d: %s an integer' % (tc, 'Always' if ok else 'Not always')) 
