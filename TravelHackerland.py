from collections import defaultdict
import heapq

def root(ids, i):
    while ids[i] != i:
        ids[i] = ids[ids[i]]
        i = ids[i]
    return i

def union(queries, blds, ids, p, q):
    i = root(ids, p)
    j = root(ids, q)
    if i == j:
        return i, j
    if len(blds[i]) > len(blds[j]):
        bigb, smb = blds[i], blds[j]
    else:
        bigb, smb = blds[j], blds[i]
    for b in smb:
        bigb.add(b)
    del smb
    if len(queries[i][0]) + len(queries[i][1]) > len(queries[j][0]) + len(queries[j][1]):
        ids[j] = i
        blds[i] = bigb
        blds[j] = None
        return j, i
    else:
        ids[i] = j
        blds[j] = bigb
        blds[i] = None
        return i, j

n, m, q = map(int, input().split())
T = list(map(int, input().split()))
edges = []
for i in range(m):
    x, y, u = map(int, input().split())
    edges.append((u, x-1, y-1))
edges.sort()
queries = [[set([]), []] for _ in range(n)]
res = [-1 for i in range(q)]
for qi in range(q):
    x, y, k = map(int, input().split())
    x, y = sorted([x-1, y-1])
    if x == y and k <= 1:
        res[qi] = 0
    else:
        qr = (k, x, y, qi)
        if x == y:
            heapq.heappush(queries[x][1], qr)
        else:
            queries[x][0].add(qr)
            queries[y][0].add(qr)
ids = [i for i in range(n)]
blds = [set([T[i]]) for i in range(n)]
for u, x, y in edges:
    i, j = union(queries, blds, ids, x, y)
    if i == j:
        continue
    tot_blds = len(blds[j])
    #print u, x, y, i, j, queries[i], queries[j], tot_blds
    for qr in queries[i][0]:
        if root(ids, qr[1]) != root(ids, qr[2]):
            queries[j][0].add(qr)
        else:
            queries[j][0].discard(qr)
            if tot_blds >= qr[0]:
                res[qr[-1]] = u
            else:
                heapq.heappush(queries[j][1], qr)
    while queries[i][1] and queries[i][1][0][0] <= tot_blds:
        res[queries[i][1][0][-1]] = u
        heapq.heappop(queries[i][1])
    for qr in queries[i][1]: 
        heapq.heappush(queries[j][1], qr)
    queries[i][0] = None
    queries[i][1] = None
    while queries[j][1] and queries[j][1][0][0] <= tot_blds:
        res[queries[j][1][0][-1]] = u
        heapq.heappop(queries[j][1])
for r in res:
    print(r)