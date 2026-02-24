class Solution {
    public int countPaths(int n, int[][] roads) {
        long MOD = 1000000007;        
        List<List<long[]>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for(int[] r : roads) {
            graph.get(r[0]).add(new long[]{r[1], r[2]});
            graph.get(r[1]).add(new long[]{r[0], r[2]});
        }
        long[] dist = new long[n];
        long[] ways = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) -> Long.compare(a[0], b[0]));
        dist[0] = 0;
        ways[0] = 1;
        pq.offer(new long[]{0, 0});
        while(!pq.isEmpty()) {
            long[] curr = pq.poll();
            long d = curr[0];
            int node = (int)curr[1];
            if(d > dist[node]) continue;
            for(long[] neighbor : graph.get(node)) {
                int adj = (int)neighbor[0];
                long time = neighbor[1];
                long newDist = d + time;
                if(newDist < dist[adj]) {
                    dist[adj] = newDist;
                    ways[adj] = ways[node];
                    pq.offer(new long[]{newDist, adj});
                }
                else if(newDist == dist[adj]) {
                    ways[adj] = (ways[adj] + ways[node]) % MOD;
                }
            }
        }
        return (int)(ways[n - 1] % MOD);
    }
}