File = open("Euler79Data.txt","r").read().split("\n")
CharactersLowerThan = dict()
for Logins in File:
    for Character in range(2):
        if(not(Logins[Character] in CharactersLowerThan)):
            CharactersLowerThan[Logins[Character]] = dict()
        if(Character == 0):
            CharactersLowerThan[Logins[Character]][Logins[Character+1]] = 1
            CharactersLowerThan[Logins[Character]][Logins[Character+2]] = 1
        else:
            CharactersLowerThan[Logins[Character]][Logins[Character+1]] = 1
#går igenom dictionaryn och tar dem lägsta keysen
NyLista = [-1,-1-1,-1,-1,-1,-1,-1,-1,-1]
for Keys in CharactersLowerThan:
    print(Keys,len(CharactersLowerThan[Keys]))