#include "SparseMatrix.h"
#include "DenseMatrix.h"

int main() {
    DenseMatrix dense(5, 5);   // Creating a 3x3 dense matrix

    dense.solves();
    dense.times();
    dense.print();  // This will print the dense matrix initialized with 0.0

    dense.nonSingularInit(10); // Insert 5 random elements into the dense matrix ensuring non-singularity
    dense.print();  // This will print the dense matrix with random elements ensuring non-singularity

    SparseMatrix sparseConverted = dense.toCSR();
    sparseConverted.print();

    return 0;
}
