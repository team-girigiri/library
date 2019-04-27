# dijkstra
辺の数がO(n)のグラフにおいて、指定した頂点から全頂点への最短経路をO(nlogn)で求める。
## usage
頂点数でコンストラクト。g.add_edge(a, b, w)でa, b間に重みwの辺を追加。add_arcで有向辺。g.run(s)でsからの最短距離を計算。
double精度なのでint程度の重みなら正確に計算できる。
## verified
https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A

# maximal_independent_set
グラフの最大独立集合を乱択で求める。40頂点ぐらいなら問題なし。
戻り値の配列は頂点サイズの配列で、頂点iが最大独立集合に含まれているならtrue, そうでないならfalse
## usage
グラフの隣接リストでコンストラクト。第2引数は探索時間
## verified
https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g
