// amount of time/space taken by the algorithm to run as a functions of the input size
// which algorithm will be a better choice for a problem
// first : time, second : space. depends on the constraints

// if we note the time, its called experimental analysis
// we will estimate the time theoritically instead

// big-O notation
// can discuss about this somewhere else

// experimental analysis : 
    /*
        library - #include <ctime>
    
        auto start_time = clock();
        sort(arr.begin(), arr.end());
        auto end_time = clock();

        cout << end_time - start_time << endl;
    */
// take different input and check if the time changes

// theoritical analysis : 
    /*
    
    */
// provides mathematical notation

// loop-based
/*
for (int i = 0; i <= n-1; i++){
    for (int j = 0; j <= n-1; j++){
        // constant work
    }
}
*/
/*
int j;
for(int i=0; i<=n-1; i = i + j){
    for(j=i+1; j<=k; j++){
        // constant work	
    }
}
*/

// bubble sort, work case - max iterations, best case - min iterations

// 