// dijkstra算法：
// dist是个列向量，大小等于|V|，记录从源点到每一个顶点的最短距离的估值
// 1. 初始化： dist[源点] = 0，dist[i] = 无穷大，i属于Q - {源点}
// 2. 从Q中弹出一个顶点u，要求dist[u] < dist[i] i属于Q（在集合Q中找出dist最小的一个顶点），再找u的出边{u, v},如果dist[v] > dist[u] + w(u,v) 则更新dist[v] = dist[u] + w(u,v)。
// 3. 循环第2步，直到Q为空。




// 以Q为集合驱动，编码不简洁，以新更新的dist为集合，因为取最小值本质上就是取dist更新点的集合最小值，补集都是无穷大不用取。所这样最洁简：
// qp为优先级queue
// pq.push(源点))
// while(pq.size()) {
//   auto u = pq.front();
//   pq.pop();
//   if (更新) {
//     pq.push()
//     更新。
//   }
//}
