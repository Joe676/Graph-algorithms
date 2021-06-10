from matplotlib import pyplot as plt

fileNames = ["dijkstra_list.txt",
             "dijkstra_matrix.txt",
             "fordbellman_list.txt",
             "fordbellman_matrix.txt",
             "kruskal_list.txt",
             "kruskal_matrix.txt",
             "prim_list.txt",
             "prim_matrix.txt",
             "fordfulkerson_bfs_list.txt",
             "fordfulkerson_bfs_matrix.txt",
             "fordfulkerson_dfs_list.txt",
             "fordfulkerson_dfs_matrix.txt"]

data = {}

for fileName in fileNames:
    with open(fileName, "r") as file:
        for line in file:
            s = line.split("\t")
            key = (fileName, int(s[0]), int(s[1]))
            if key in data.keys():
                data[key] += int(s[2])
            else:
                data[key] = int(s[2])

for k, v in data.items():
    data[k] = v/100

# TYPE 2

# x = [500, 1000, 1500, 2000, 2500, 3000, 3500]
x = [100, 150, 200, 250, 300, 350, 400]

alg1_list = [0]*7
alg1_matrix = [0]*7
alg2_list = [0]*7
alg2_matrix = [0]*7

density = 99

for k, v in data.items():
    if k[2] == density:
        if k[0] == fileNames[8]:
                alg1_list[k[1]//50-2] = v
        elif k[0] == fileNames[9]:
                alg1_matrix[k[1]//50-2] = v    
        elif k[0] == fileNames[10]:
                alg2_list[k[1]//50-2] = v
        elif k[0] == fileNames[11]:
                alg2_matrix[k[1]//50-2] = v

plt.plot(x, alg1_list, label="Ford-Fulkerson BFS List")
plt.plot(x, alg1_matrix, label="Ford-Fulkerson BFS Matrix")
plt.plot(x, alg2_list, label="Ford-Fulkerson DFS List")
plt.plot(x, alg2_matrix, label="Ford-Fulkerson DFS Matrix")
plt.title("Gęstość {}%".format(density))
plt.legend()
plt.show()
# # TYPE 1
# x = [100, 150, 200, 250, 300, 350, 400]
# # x = [500, 1000, 1500, 2000, 2500, 3000, 3500]
# alg1_20 = [0]*7
# alg1_60 = [0]*7
# alg1_99 = [0]*7
# alg2_20 = [0]*7
# alg2_60 = [0]*7
# alg2_99 = [0]*7

# for k, v in data.items():
#     if k[0] == fileNames[9]:
#         print(k, v)
#         if k[2] == 20:
#             alg1_20[k[1]//50-2] = v
#         elif k[2] == 60:
#             alg1_60[k[1]//50-2] = v
#         elif k[2] == 99:
#             alg1_99[k[1]//50-2] = v
#     if k[0] == fileNames[11]:
#         if k[2] == 20:
#             alg2_20[k[1]//50-2] = v
#         elif k[2] == 60:
#             alg2_60[k[1]//50-2] = v
#         elif k[2] == 99:
#             alg2_99[k[1]//50-2] = v

# plt.plot(x, alg1_20, label="Ford-Fulkerson BFS 20%")
# plt.plot(x, alg1_60, label="Ford-Fulkerson BFS 60%")
# plt.plot(x, alg1_99, label="Ford-Fulkerson BFS 99%")
# plt.plot(x, alg2_20, label="Ford-Fulkerson DFS 20%")
# plt.plot(x, alg2_60, label="Ford-Fulkerson DFS 60%")
# plt.plot(x, alg2_99, label="Ford-Fulkerson DFS 99%")
# plt.legend()
# plt.show()