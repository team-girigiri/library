# lowest_common_ancestor
最小共通祖先をEuler tour + SparseTableで構築O(NlogN), クエリ毎O(1)で求める。
## usage
木の隣接リストでコンストラクト。dist(a, b)でa, b間のパスの長さ（辺の重みは1）も求まる
## verified
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
