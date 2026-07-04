class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxHeap = [-x for x in stones]
        heapq.heapify(maxHeap)
        while len(maxHeap) > 1:
            top = heapq.heappop(maxHeap)
            second = heapq.heappop(maxHeap)
            if top == second:
                continue
            else:
                heapq.heappush(maxHeap, (top - second))
        if maxHeap:
            return -heapq.heappop(maxHeap)
        else:
            return 0
        

"""
    two heaviest stones means we need to use a max heap

"""