# https://leetcode.com/problems/design-a-food-rating-system/

from sortedcontainers import SortedList

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cui2food = defaultdict(SortedList)
        self.food2cui = {}
        for food, cui, rate in zip(foods, cuisines, ratings):
            self.cui2food[cui].add((-rate, food))
            self.food2cui[food] = (cui, rate)

    def changeRating(self, food: str, newRating: int) -> None:
        cui, rate = self.food2cui[food]
        self.food2cui[food] = (cui, newRating)
        self.cui2food[cui].remove((-rate, food))
        self.cui2food[cui].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.cui2food[cuisine][0][1]
        


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
