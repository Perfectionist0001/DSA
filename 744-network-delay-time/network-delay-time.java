class Solution {
    class Pair {
        int node;
        int distance;
        Pair(int node, int distance) {
            this.node = node;
            this.distance = distance;
        }
    }
    public int networkDelayTime(int[][] times, int n, int k) {
        ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < times.length; i++) {
            int from = times[i][0];
            int to = times[i][1];
            int time = times[i][2];
            adj.get(from).add(new Pair(to, time));
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (a, b) -> a.distance - b.distance
        );
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;
        pq.add(new Pair(k, 0));
        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int node = curr.node;
            int d = curr.distance;
            if (d > dist[node]) continue;
            for (Pair neighbor : adj.get(node)) {
                int adjNode = neighbor.node;
                int wt = neighbor.distance;
                if (dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
                    pq.add(new Pair(adjNode, dist[adjNode]));
                }
            }
        }
        int max = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            max = Math.max(max, dist[i]);
        }
        return max;
    }
}
