#User function Template for python3

# design the class in the most optimal way

class LRUCache:
      
    key_value = {}

    
    def __init__(self, cap):
        self.cap = cap  
        self.cache = {}  
        self.usage_order = [] 

    
    def get(self, key):
        if key in self.cache:
            
           
            self.usage_order.remove(key)
            self.usage_order.append(key)
            return self.cache[key]
        else:
            return -1  

    
    def put(self, key, value):
        if key in self.cache:
            
            self.cache[key] = value
            self.usage_order.remove(key) 
        else:
           
            if len(self.cache) >= self.cap:
                least_used_key = self.usage_order.pop(0)
                del self.cache[least_used_key]

            
            self.cache[key] = value

        
        self.usage_order.append(key)

        
        LRUCache.key_value[key] = value




#{ 
 # Driver Code Starts
#Initial Template for Python 3


def inputLine():
    return input().strip().split()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        capacity = int(input())
        cache = LRUCache(capacity)

        queries = int(input())
        for __ in range(queries):
            vec = inputLine()
            if vec[0] == "PUT":
                key = int(vec[1])
                value = int(vec[2])
                cache.put(key, value)
            else:
                key = int(vec[1])
                print(cache.get(key), end=" ")
        print()
        print("~")

# } Driver Code Ends