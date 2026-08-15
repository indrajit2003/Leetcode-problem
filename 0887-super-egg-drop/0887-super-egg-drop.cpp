class Solution {
public:
    int findTotalFloor(int eggs,int moves){
        if(eggs==0 or moves==0) return 0;
        if(eggs==1) return moves;
        return 1+findTotalFloor(eggs-1,moves-1)+findTotalFloor(eggs,moves-1);
    }
    int superEggDrop(int k, int n) {
        int moves = 0;
        while(findTotalFloor(k,moves)<n){
            moves++;
        }
        return moves;
    }
};