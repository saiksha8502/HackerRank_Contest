root = {}
def add_to(root,s):
    current_node = root.setdefault(s[0],[0,{}])
    if len(s) == 1:
        current_node[0] += 1
    else:
        add_to(current_node[1],s[1:]) 
def is_prefix(root,s):
    if len(s) == 1:
        if len(root[s[0]][1])>0 or root[s[0]][0] > 1:
            return True
        else:
            return False
    else:
        if root[s[0]][0] > 0:
            return True
        else:
            return is_prefix(root[s[0]][1],s[1:])
n = int(input())
count = 0 
for _ in range(n):
    word = input().strip()
    add_to(root,word)
    if is_prefix(root,word):
        print("BAD SET")
        print(word)
        break
    count += 1
if count == n:
    print("GOOD SET")
