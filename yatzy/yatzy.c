#include <stdio.h>
#include <stdbool.h>

int test_rul[13][6] = {
                    {1,2,3,4,5,0} //0
                    ,{1,2,3,4,5,0} 
                    ,{1,2,3,4,5,0}
                    ,{1,2,3,4,5,0}
                    ,{1,2,3,4,5,0}
                    ,{1,2,3,4,5,0} //5
                    ,{1,2,3,4,5,0}
                    ,{1,2,3,4,5,0}
                    ,{1,2,3,4,5,0}
                    ,{1,2,3,4,5,0}
                    ,{1,2,3,4,5,0} //10
                    ,{1,2,3,4,5,0} 
                    ,{1,2,3,4,5,0}}; 


int category_filled[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
int category_scores[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

bool n_of_a_kind_cat_11(int roll_id) {
    int i;
    int k;
    int count_of_same = 0;
    int highest_count_of_same = 0;

    for (i=0; i<5; i++) {
        for (k=0; k<5; k++) {
            if (test_rul[roll_id][i] == test_rul[roll_id][k] && i!=k) {
                return true;
            }
        }
    }
    
    return false;
}

bool n_of_a_kind(int roll_id, int n) {
    
    int i;
    int k;
    int count_of_same = 0;
    int highest_count_of_same = 0;

    for (i=0; i<5; i++) {
        for (k=0; k<5; k++) {
            if (test_rul[roll_id][i] == test_rul[roll_id][k] && i!=k) {
                count_of_same+=1;
            }
        }
        if (count_of_same>highest_count_of_same) {
            highest_count_of_same=count_of_same;
        }
        count_of_same=0;
    }

    if (highest_count_of_same >= n) {
        return true;
    } else {
        return false;
    }

}


bool check_for_house(int j) {
    int i;
    int k;
    int count_of_same = 0;
    int highest_count_of_same = 0;
    bool house_roof = false;

    for (i=0; i<5; i++) {
        for (k=0; k<5; k++) {
            if (test_rul[j][i] == test_rul[j][k]) {
                count_of_same+=1;
            }
        }
        if (count_of_same>highest_count_of_same) {
            if (count_of_same==2) {
                house_roof = true;
            }
            highest_count_of_same=count_of_same;
        }

        if (highest_count_of_same==3 && house_roof==true) {
            return true;
        }

        if (highest_count_of_same==3 && count_of_same==2) {
            return true;
        }
        
        count_of_same=0;
    }
    return false;
}

int find_points_for_roll_used_on_category(int roll_id, int category_id) {
int points_for_category = 0;
int k;

    if (category_id==0 && category_filled[category_id] == 0) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] ==1) {
                count_of_same+=1;
            }
        }
        sum=count_of_same;
        return sum;
    }

    if (category_id==1 && category_filled[category_id] == 0) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] == category_id+1) {
                count_of_same+=1;
            }
        }
        sum=(category_id+1)*count_of_same;
        return sum;

    }

    if (category_id==2 && category_filled[category_id] == 0) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] == category_id+1) {
                count_of_same+=1;
            }
        }
        sum=(category_id+1)*count_of_same;
        return sum;
    }

    if (category_id==3 && category_filled[category_id] == 0) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] == category_id+1) {
                count_of_same+=1;
            }
        }
        sum=(category_id+1)*count_of_same;
        return sum;
    }

    if (category_id==4 && category_filled[category_id] == 0) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] == category_id+1) {
                count_of_same+=1;
            }
        }
        sum=(category_id+1)*count_of_same;
        return sum;
    }

    if (category_id==5 && category_filled[category_id] == 0) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] == category_id+1) {
                count_of_same+=1;
            }
        }
        sum=(category_id+1)*count_of_same;
        return sum;
    }

    if (category_id==6 && category_filled[category_id] == 0) {
        int sum=0;
        for (k=0; k<5; k++) {
            sum+=test_rul[roll_id][k];
        }
        return sum;
    }

    if (category_id==7 && category_filled[category_id] == 0) {
        int sum=0;
        if (n_of_a_kind(roll_id, 3)==true) {
            for (k=0; k<5; k++) {
                sum+=test_rul[roll_id][k];
            }
            return sum;
        }
        return sum;
    }

    if (category_id==8 && category_filled[category_id] == 0) {
        int sum=0;
        if (n_of_a_kind(roll_id, 4)==true) {
            for (k=0; k<5; k++) {
                sum+=test_rul[roll_id][k];
            }
            return sum;
        }
        return sum;
    }

    if (category_id==9 && category_filled[category_id] == 0) {
        int sum=0;
        if (n_of_a_kind(roll_id, 5)==true) {
            for (k=0; k<5; k++) {
                sum+=test_rul[roll_id][k];
            }
            return sum;
        }
        return sum;
    }

    if (category_id==10 && category_filled[category_id] == 0) {
        int sum=0;
        if (n_of_a_kind(roll_id,3) == false) {
            return 25;
        }
        return sum;
    }

    if (category_id==11 && category_filled[category_id] == 0) {
        int sum=0;
        if (n_of_a_kind_cat_11(roll_id) == false) {
            return 35;
        }
        return sum;

    }

    if (category_id==12 && category_filled[category_id] == 0) {
        int sum=0;
        if (check_for_house==true) {
            return 40;
        }
        return sum;

    }   

    return 0;
}




int find_best_category_for_roll(int roll_id) {

    int points_for_category = 0;
    int highest_score = 0;
    int highest_score_category_id = -1;


    for (int category_id=0; category_id<13; category_id++) {

        points_for_category=find_points_for_roll_used_on_category(roll_id, category_id);
        if (points_for_category>highest_score) {
            highest_score=points_for_category;
            highest_score_category_id=category_id;
        }
    }
    return highest_score_category_id;
    

}


int main () {

    //find best category for a roll/round:
    for (int i=0; i<13; i++) {
        category_filled[find_best_category_for_roll(i)] = 1;
        category_scores[find_best_category_for_roll(i)] = find_points_for_roll_used_on_category(i, find_best_category_for_roll(i));
    }

    for (int i=0; i<13; i++) {
    printf("%d ",category_scores[i]);
    }
    bool bonus = true;
    int sum=0;

    for (int i; i<5; i++) {
        sum+=category_scores[i];
    }

    if (sum<63) {
        bonus=false;
    }
    
    if (bonus == true) {
        printf("%d ", 35);
    } else {
        printf("0 ");
    }

    sum=0;    
    for (int i=0; i<13;i++) {
        sum += category_scores[i];
    }

    if (bonus == true) {
        sum+=35;
    }

    printf("%d ", sum);
    
}