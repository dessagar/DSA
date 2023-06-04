class Hashing:
    def __init__(self, size):
        self.size = size
        self.count = 0
        self.hashTable = [None] * size
   

    def hashFunction(self, ele):
        return ele % self.size

    def isFull(self):
        return self.count == self.size

    def inserting(self, ele):
        if self.isFull():
            print("Hash table is full.")
        else:
            index = self.hashFunction(ele)
            if self.hashTable[index] is None:
                self.hashTable[index] = ele
                self.count += 1
                print("Element", ele, "inserted successfully.")
                print(self.hashTable)
            else:
                self.collision(ele)

    def collision(self, ele):
        print("\n1 - Linear Probing\n2 - Quadratic Probing")
        ch = int(input("Enter your choice: "))
        if ch == 1:
            self.linearProbing(ele)
        elif ch == 2:
            self.quadraticProbing(ele)
        else:
            print("Invalid choice.")

    def linearProbing(self, ele):
        index = self.hashFunction(ele)
        while self.hashTable[index] is not None:
            index = (index + 1) % self.size
        self.hashTable[index] = ele
        self.count += 1
        print("Element", ele, "inserted successfully.")
        print(self.hashTable)

    def quadraticProbing(self, ele):
        index = self.hashFunction(ele)
        i = 1
        while self.hashTable[index] is not None:
            index = (index + i ** 2) % self.size
            i += 1
        self.hashTable[index] = ele
        self.count += 1
        print("Element", ele, "inserted successfully.")
        print(self.hashTable)


i
size = int(input("Enter the size of the table: "))
obj = Hashing(size)
n = int(input("Enter how many numbers you want to add: "))
for i in range(n):
    ele = int(input("Enter element to insert: "))
    obj.inserting(ele)



# https://justpaste.it/jp1

