#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void optimalPage(int pg[], int pn, int fn) 
{ 

    // Create an array for given number of 

    // frames and initialize it as empty. 

    vector<int> fr; 

  

    // Traverse through page reference array 

    // and check for miss and hit. 

    int hit = 0; 

    for (int i = 0; i < pn; i++) { 

  

        // Page found in a frame : HIT 

        if (search(pg[i], fr)) { 

            hit++; 

            continue; 

        } 

  

        // Page not found in a frame : MISS 

  

        // If there is space available in frames. 

        if (fr.size() < fn) 

            fr.push_back(pg[i]); 

  

        // Find the page to be replaced. 

        else { 

            // int c = predict(pg, fr, pn, i + 1); 

            int res=-1, far=i+1;

            for(j=0;j<sizeofframe;j++)
            {
                for(k=i+1;k<sizeofref;k++)
                {
                    
                }
            }

            fr[c] = pg[i]; 

        } 

    } 

    cout << "No. of hits = " << hit << endl; 

    cout << "No. of misses = " << pn - hit << endl; 
} 

int predict(int pg[], vector<int>& fr, int pn, int index) 
{ 

    // Store the index of pages which are going 

    // to be used recently in future 

    int res = -1, farthest = index; 

    for (int i = 0; i < fr.size(); i++) 
    { 

        int j; 

        for (j = index; j < pn; j++) { 

            if (fr[i] == pg[j]) { 

                if (j > farthest) { 

                    farthest = j; 

                    res = i; 

                } 

                break; 

            } 

        } 
        // If a page is never referenced in future, 

        // return it. 

        if (j == pn) 

            return i; 

    } 

    // If all of the frames were not in future, 

    // return any of them, we return 0. Otherwise 

    // we return res. 
    return (res == -1) ? 0 : res; 
} 