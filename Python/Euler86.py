from math import *
def ShortestPath(Side1,Side2,Side3):
    Path1 = ((Side1+Side2)**2+Side3**2)
    Path2 = ((Side1+Side3)**2+Side2**2) 
    Path3 = ((Side2+Side3)**2+Side1**2)
    Shortest = min(Path1,Path2,Path3)
    if(round(sqrt(Shortest))**2 == Shortest):
        return(True)
    else:
        return(False)
def GeneratePrimitiveTriplats(MaxSideLength):
    TripletsList = []
    for p in range(1,MaxSideLength):
        if(max(2*p*(p+1),(p+1)**2-p**2) > 2*MaxSideLength or min(2*p*(p+1),(p+1)**2-p**2) > MaxSideLength):
            break 
        for q in range(p+1,MaxSideLength):
            if(not gcd(p,q)==1 or (p+q)%2 == 0):
                continue
            Side1 = 2*p*q
            Side2 = q**2-p**2
            Side3 = q**2+p**2
            MaxSide = max(Side1,Side2)
            #if(gcd(Side1,gcd(Side2,Side3)) != 1):
            #    continue
            if(MaxSide > 2*MaxSideLength or min(Side1,Side2) > MaxSideLength):
                break
            TripletsList.append([Side1,Side2,Side3])
    return(TripletsList)
def CubeFromTriplet(a,b,Max):
    #vi börjar att anta att a är den ensamma sidan
    Z = a
    ReturnValue = 0
    if(Z <= Max):
        Kombinationer = ceil((b-1)/2)
        if(b > Z):
            Kombinationer-=(b-1-Z)
            if(Kombinationer < 0):
                Kombinationer = 0
        ReturnValue+=Kombinationer
    Z = b
    if(Z <= Max):
        Kombinationer = ceil((a-1)/2)
        if(a > Z):
            Kombinationer-=(a-1-Z)
            if(Kombinationer < 0):
                Kombinationer = 0
        ReturnValue+=Kombinationer
    return(ReturnValue)
M = 1000
while(True):
    NumberOfRectangles = 0
    if(M%100 == 0):
        print(M)
    ListOfTriplets = GeneratePrimitiveTriplats(M)
    for index,Triplet in enumerate(ListOfTriplets):
        i = 1
        while(max(Triplet[0]*i,Triplet[1]*i) <= 2*M and min(Triplet[0]*i,Triplet[1]*i) <= M):
            NumberOfRectangles+=CubeFromTriplet(Triplet[0]*i,Triplet[1]*i,M)
            i+=1
    if(NumberOfRectangles > 10**7):
        break
    M+=1
print(M)