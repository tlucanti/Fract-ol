##
#	Author:		antikostya
#	Created:	2021-10-02 16:41:38
#	Modified:	2021-10-02 19:01:33
##

import numpy as np

viridis = np.array([
	(68,1,84),
	(72,36,117),
	(65,68,135),
	(53,95,141),
	(42,120,142),
	(33,144,141),
	(34,168,132),
	(66,190,113),
	(122,209,81),
	(189,223,38)
])


inferno = np.array([
	(0,0,4),
	(22,11,57),
	(66,10,104),
	(106,23,110),
	(147,38,103),
	(186,54,85),
	(221,81,58),
	(243,118,27),
	(252,165,10),
	(246,215,70)
])

rainbow = np.array([
	(110,64,170),
	(190,60,175),
	(254,75,131),
	(255,119,71),
	(227,182,47),
	(176,239,90),
	(83,246,102),
	(30,223,162),
	(35,172,216),
	(76,111,220)
])

array = rainbow

x = np.linspace(0, 1, 10)
print('{')
for i in range(9):
	# print('\t', end='')
	# if (i != 0):
	# 	print('} else ', end='')
	# if (i < 8):
	# 	print(f'if (i < {"" if i == 0 else str(i + 1) + " *"} ONE_NINETH)' + ' {')
	# if (i == 8):
	# 	print('{')
	# for v, rgb in enumerate((array[:,0], array[:,1], array[:,2])):
	# 	va = ['r', 'g', 'b'][v]
	# 	xa, xb = x[i], x[i + 1]
	# 	ya, yb = rgb[i], rgb[i + 1]
	# 	k = (yb - ya) / (xb - xa)
	# 	b = ya - (yb - ya) * xa / (xb - xa)
	# 	print(f'\t\t{va} = {int(k)} * i {"-" if b < 0 else "+"} {abs(int(b))};')
	#
	print('\t', end='')
	if (i != 0):
		print('else ', end='')
	if (i < 8):
		print(f'if (i < {"" if i == 0 else str(i + 1) + " *"} ONE_NINETH)')
	if (i == 8):
		print()
	for v, rgb in enumerate((array[:,0], array[:,1], array[:,2])):
		va = 'rgb'[v]
		xa, xb = x[i], x[i + 1]
		ya, yb = rgb[i], rgb[i + 1]
		k = (yb - ya) / (xb - xa)
		b = ya - (yb - ya) * xa / (xb - xa)
		print('\t\treturn (' if va == 'r' else '', end='')
		print(f'(int)({int(k)} * i {"-" if b < 0 else "+"} {abs(int(b))})', end='')
		print(f' << {16 if va == "r" else 8} | ' if va in 'rg' else '', end=');\n' if va=='b' else '')
print('}')
