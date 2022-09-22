#include <stdio.h>
#include <stdbool.h>

//Lige nu finder programmet den optimale kategori at bruge nr. x rul på. Array adresse er kategori, og data er rul nr.
//Mangler at skrive en funktion der spørger: Hvilket rul ønskes at blive brugt til flere kategorier?
//Funktion til at beregne point for hver kategori med givent rul. Slet herefter denne funktion fra overvejelserne, og genevaluer. (sæt array række =0 ?? Nej, da det vil skabe en forvirring for 5 ens. Skriv en funktion der udelukkker værdier)


//int rul[5][13] = {0};
int test_rul[13][6] = {
                    {1,1,1,1,1,0} //0
                    ,{6,6,6,6,6,0} 
                    ,{6,6,6,1,1,0}
                    ,{1,1,1,2,2,0}
                    ,{1,1,1,2,3,0}
                    ,{1,2,3,4,5,0} //5
                    ,{1,2,3,4,6,0}
                    ,{6,1,2,6,6,0}
                    ,{1,4,5,5,5,0}
                    ,{5,5,5,5,6,0}
                    ,{4,4,4,5,6,0} //10
                    ,{3,1,3,6,3,0} 
                    ,{2,2,2,4,6,0}}; 
bool category_filled[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
int best_roll_for_category[13] = {-1};
int point_for_roll_in_category[13] = {0};

void type_roll() {
    int input_number;
    int i;
    int j;

    printf("Type your first 5 numbers");
    for (i=0; i<13; i++) {
        for (j=0; j<5; j++) {
            scanf("%d", input_number);
            //rul[j][i] = input_number;
        }
    printf("Type your next 5 numbers");
}
}

void category_of_sums() {
int sum_of_i = 0;
int highest_sum_of_i = 0;

int i;
int j;
int k;
int best_roll_row_id = -1;

for (i=0; i<6; i++) {
    for (j = 0; j < 13; j++) {
        for (k = 0; k < 5; k++){
            if (test_rul[j][k] == i+1) {
                sum_of_i+=i+1;
            }
        }
        if (sum_of_i>highest_sum_of_i) {
            highest_sum_of_i=sum_of_i;
            best_roll_row_id = j;
            }
        sum_of_i = 0;

    }
    best_roll_for_category[i] = best_roll_row_id;
    highest_sum_of_i=0;
}
}

int find_points_for_roll_used_on_category(int roll_id, int i) {

    //Hav bestemt hvilke funktioner der skal betragtes her.
    //Funktionen skal måske bare lave et array af alle funktionsværdier? Så returner den hvilken funktion der giver højest funktionsværdi

    int k;
    int points = 0;

    //cat0//cat
    if (i==0) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] ==i+1) {
                count_of_same+=1;
            };
        }
        sum=(i+1)*count_of_same;
        return sum;
    }
    
    //cat
    if (i==1) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] ==i+1) {
                count_of_same+=1;
            };
        }
        sum=(i+1)*count_of_same;
        return sum;
    }

    //cat
    if (i==2) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] ==i+1) {
                count_of_same+=1;
            };
        }
        sum=(i+1)*count_of_same;
        return sum;
    }

    //cat
    if (i==3) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] ==i+1) {
                count_of_same+=1;
            };
        }
        sum=(i+1)*count_of_same;
        return sum;
    }


    //cat
    if (i==4) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] ==i+1) {
                count_of_same+=1;
            };
        }
        sum=(i+1)*count_of_same;
        return sum;
    }

    //cat
    if (i==5) {
        int count_of_same = 0;
        int sum = 0;
         for (k=0; k<5; k++) {
            if (test_rul[roll_id][k] ==i+1) {
                count_of_same+=1;
            };
        }
        sum=(i+1)*count_of_same;
        return sum;
    }

    //cat
    if (i==6) {
        for (k=0; k<5; k++) {
            points+=test_rul[roll_id][k];
        }
        return points;
    }

    //cat
    if (i==7) {
        for (k=0; k<5; k++) {
            points+=test_rul[roll_id][k];
        }
        return points;
    }

    //cat
    if (i==8) {
        for (k=0; k<5; k++) {
            points+=test_rul[roll_id][k];
        }
        return points;
    }

    //cat
    if (i==9) {
        return 50;
    }

    //cat10
    if (i==10) {
        return 25;
    }

    //cat11
    if (i==11) {
        return 35;
    }

    //cat12
    if (i==12) {
        return 40;
    }

    //Sammenlign funktionsværdier for kombinationer der begge (eller flere) ønsker at bruge ét rul.

    return 0;
}

//Funktion til at sammenligne 
int find_best_category_for_roll(int roll_id1, int category_row_id1, int category_row_id2) {

    if (find_points_for_roll_used_on_category(roll_id1,category_row_id1) > find_points_for_roll_used_on_category(roll_id1,category_row_id2 )) {
        return category_row_id1;
    } else if (find_points_for_roll_used_on_category(roll_id1,category_row_id1) < find_points_for_roll_used_on_category(roll_id1,category_row_id2 )) {
        return category_row_id2;
    }

    //I tilfælde hvor de giver samme point, så ignorer og kør videre.
    if (find_points_for_roll_used_on_category(roll_id1,category_row_id1) == find_points_for_roll_used_on_category(roll_id1,category_row_id2 )) {
        return -1;
    }
}

void remove_roll_and_category_from_evaluation(int rollid, int category_id) {

    category_filled[category_id] = true;

    int k;
    for (k=0; k<4; k++) {
        test_rul[rollid][k]=-1;
    }

    test_rul[rollid][4] = -2;

    test_rul[rollid][5] = 1;

}


bool n_of_a_kind(int j, int n) {
    
    int i;
    int k;
    int count_of_same = 0;
    int highest_count_of_same = 0;

    for (i=0; i<5; i++) {
        for (k=0; k<5; k++) {
            if (test_rul[j][i] == test_rul[j][k]) {
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



void eval_false_categories_with_rest() {

    int i;
    int j;
    int k;
    
    int current_chance = 0;
    int highest_chance = 0;


    for (i=0;i<13;i++) {
        if (test_rul[i][5] == false) {
            for (j = 0; j < 13; j++) {

            for (k = 0; k < 5; k++){
                
                //Sum of current chance
                if (i==6) {
                    current_chance+=test_rul[j][k];
                }

                if (i==7 && n_of_a_kind(j,3)==true) {
                    current_chance+=test_rul[j][k];
                }

                if (i==8 && n_of_a_kind(j,4)==true) {
                    current_chance+=test_rul[j][k];
                }

                if (i==9 && n_of_a_kind(j,5)==true) {
                    current_chance=50; //Her gælder det for flere. Den defineres derfor ikke efter j=0. Skriv en funktion til at holde styr på 'lige gode' muligheder.
                }

                if (i==10 && n_of_a_kind(j,3)==false) {
                    current_chance=25;
                }; //Kode til betingelse 10

                if (i==11 && n_of_a_kind(j,2)==false) {
                    current_chance=35;
                }

                if (i==12 && check_for_house(j) == true) {
                        current_chance=40;
                }; //Kode til betingelse 12

                }

            //Check if highest chance
            if (current_chance>=highest_chance && current_chance!=0) {
                highest_chance=current_chance;
                best_roll_for_category[i]=j;
                //Lav condition om til current>highest, og lav anden if for (==), da de skal tjekkes senere.
            } 
            current_chance=0;

            }
        }
        highest_chance=0;
    }
}



void rest_of_categories() {
    int i;
    int j;
    int k;
    
    int current_chance = 0;
    int highest_chance = 0;

    for (i=6; i<13; i++) {
        for (j = 0; j < 13; j++) {
            for (k = 0; k < 5; k++){
                
                //Sum of current chance
                if (i==6) {
                    current_chance+=test_rul[j][k];
                }

                if (i==7 && n_of_a_kind(j,3)==true) {
                    current_chance+=test_rul[j][k];
                }

                if (i==8 && n_of_a_kind(j,4)==true) {
                    current_chance+=test_rul[j][k];
                }

                if (i==9 && n_of_a_kind(j,5)==true) {
                    current_chance=50; //Her gælder det for flere. Den defineres derfor ikke efter j=0. Skriv en funktion til at holde styr på 'lige gode' muligheder.
                }

                if (i==10 && n_of_a_kind(j,3)==false) {
                    current_chance=25;
                }; //Kode til betingelse 10

                if (i==11 && n_of_a_kind(j,2)==false) {
                    current_chance=35;
                }

                if (i==12 && check_for_house(j) == true) {
                        current_chance=40;
                }; //Kode til betingelse 12

                }

            //Check if highest chance
            if (current_chance>=highest_chance && current_chance!=0) {
                highest_chance=current_chance;
                best_roll_for_category[i]=j;
                //Lav condition om til current>highest, og lav anden if for (==), da de skal tjekkes senere.
            } 
            current_chance=0;

            }
            highest_chance=0;
        }
    }

void eval_all_categories() {
    //Category of sum returnerer det optimale array for de første 6 kategorier. Holdes seperat, da der skal laves udregning med hvorvidt det er værd at skifte ud for at få bonus senere.
    category_of_sums();

    //For the rest of the categories
    rest_of_categories();

    optimal_to_amount_of_category();
}

//Function to check if one roll is optimal for multiple categories:
void optimal_to_amount_of_category() {
    int i;
    int j;
    int roll_in_question;
    bool fordeling_done = false;
    int best_category_for_roll = -1;


    for (i=10; i<13; i++) {
        for (j=0; j<13; j++) {
            if (best_roll_for_category[i] == best_roll_for_category[j] && i!=j) {
                bool fordeling_done = false;
                //Gem i variabel hvilke funktioner den skal sammenligne.
                if (find_points_for_roll_used_on_category(best_roll_for_category[i],i) > find_points_for_roll_used_on_category(best_roll_for_category[j],j)) {
                    best_category_for_roll=i;
                }


            } else {
                //Når alle har optimale rul, vil programmet have defineret det optimale rul til hver kategori.
                //Kode til beregne sum for hver kategori med optimale rul, og indsæt i array[13+1+1] (13kat,bonus?,sum)
            }

            //Nu har den fundet den optimale kategori og gemt den i best_category_for_roll.
            //Lav et array af true/false for om der er fundet optimal kategori med sikkerhed.
            //finished_category[i] = true;
            //Edit original array roll id. Fjern
            //done ovenfor



            //genevaluer for raekker hvor finished_category == false;

            eval_false_categories_with_rest();

        }
    }
    if (fordeling_done == false) {
        printf("Der er flere kategorier der ønsker at bruge samme rul. Giv rul til den der giver flest point. \n");

        //find_best_category_for_roll()
    }
    
}


int main () {

    //Ask for input numbers
    //type_roll();


    //Function to evaluate the best option for roll of each category. Some will probably overlap.
    eval_all_categories();
    int i;


    for (i=0; i<13; i++) {
        printf("%d \n", best_roll_for_category[i]);
    }

}

