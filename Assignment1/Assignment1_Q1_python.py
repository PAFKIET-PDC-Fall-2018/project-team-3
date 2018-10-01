from array import array
arr = array('i',[])
for i in range(20):
    x = int(input('Enter number for index {} :'.format(i)))
    while x < 10 or x > 100:
        x = int(input('Enter number for index {} :'.format(i)))
    if x in arr:
        pass
    else:
        print(x)
    arr.append(x)
