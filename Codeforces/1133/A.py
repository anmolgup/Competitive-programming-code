a = input()
b = input()
temp = a[0] + a[1]
temp2 = a[3] + a[4]

# print(temp)
# print(temp2)
total_min = int(temp)*60 + int(temp2)
# print(total_min)
temp3 = b[0] + b[1]
temp4 = b[3] + b[4]
# print(temp3)
# print(temp4)

temp5 = int(temp3)*60 + int(temp4)
# print(temp5)

total_min = temp5 - total_min

total_min /= 2
# print(total_min)

hr_inc = total_min//60
min_inc = total_min%60

ans1 = int(temp2) + min_inc
# print(hr_inc)
hr_inc += ans1/60
hr_inc += int(temp)

ans1 %= 60

# print(hr_inc)
hr_inc = int(hr_inc)
ans1 = int(ans1)
# print(len(str(hr_inc)))
# print(ans1)
if len(str(hr_inc)) < 2:
	print("0",end= "")

print(int(hr_inc),end="")
print(":",end="")
if len(str(ans1)) < 2:
	print("0",end= "")

print(int(ans1))
	# print

# if ans1 > 59:
	# ans