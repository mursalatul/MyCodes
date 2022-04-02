#include <stdio.h>
#include <complex.h>

// this input function will take both integer and imaginary numbers
double complex input()
{
    // real = real part of a number. 2 - 3i....here 2 is real
    // imagi = constant part of a imaginary number. 2 - 3i...here -3 is imagi
    double real = 0, imagi = 0;
    double complex x;
    printf("Enter the real number part(enter 0 if not available): ");
    scanf("%lf", &real);
    printf("Enter the real number with imaginary number part(enter 0 if not available): ");
    scanf("%lf", &imagi);
    // combiniting the two parts and creating a complete complex number
    x = CMPLX(real, imagi);
    return x;
}

int main()
{
    printf("\033[33mProgram to find if a matrix hermitian or not.\n");
    // taking the dimenstion
    int r, c; // r = row ,c = column
    printf("\033[37mEnter the row and column: ");
    scanf("%d %d", &r, &c);

    // hermitian matrix is a square matrix
    if (r != c)
    {
        printf("row and column must be equal\n");
        return 0;
    }

    double complex matA[r][c];
    double complex inputed_data;
    // taking the elements
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("\tA%d%d\n", i + 1, j + 1);
            matA[i][j] = input();
            // checking if there is any imaginary number in the main diagonal
                // hermitian matrix cant hold imaginary number in main diagonal
            if (i == j && cimag(matA[i][j]) != 0.00)
            {
                printf("\033[31mMain Diagonal must be of real numbers.\nYou entered a imaginary number in main diagonal.");
                return 0;
            }
        }
    }

    // checking if
    double real_part1, real_part2, imagi_part1, imagi_part2;
    // when we conjugate a complex number it is also return a complex number
        // thats why i used double complex type variable conju
    double complex conju;
    for (int i = 0; i < r - 1; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            real_part1 = creal(matA[i][j]); // real part of element 1
            real_part2 = creal(matA[j][i]); // real part of element 2
            imagi_part1 = cimag(matA[i][j]); // imaginary part of element 1
            // we conjugate the element 2 so that we can check if they are same or not
            // and if they are same signed after conjugate. it the are same and same signed
            // after conjugate the element 2 then they can fullfil the conditions
            // of hermitian matrix
            conju = conj(matA[j][i]); // conjugating the element 2
            imagi_part2 = cimag(conju); // imaginary part of element 2
            // 2 element is hermitian when their real parts are same and
            // imaginary parts are same and reversed signed. 
            if (real_part1 != real_part2 || imagi_part1 != imagi_part2)
            {
                // if any element fullfill this 2 condition then the full matrix
                // is not hermitian
                printf("\033[31mEntered matrix is not hermitian\n");
                return 0;
            }
        }
    }
    // if every element fullfil the condition for begin a hermitian matrix then the
    // program can to this line.
    printf("\033[32mEntered matrix is hermitian\n");
    return 0;
}