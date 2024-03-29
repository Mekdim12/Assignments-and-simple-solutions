def ChangeList():
    L = []
    L2 = []
    L3 = []

    for i in range(1, 10):
        L.append(i)
    for i in range(10,1,-2):
        L2.append(i)
    
    for i in range(len(L2)):
        L3.append(L[i] + L2[i])
        L3.append(len(L) - len(L2))

    print(L2)

if __name__ == "__main__":
    ChangeList()


#  output [10, 8, 6, 4, 2]