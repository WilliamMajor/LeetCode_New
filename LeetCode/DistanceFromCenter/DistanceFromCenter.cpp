// DistanceFromCenter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>


int32_t DistanceFromCenter(int32_t inputValue, int32_t arraySize);
std::unordered_map<int32_t, std::pair<int32_t, int32_t>> GenerateMatrix(int32_t iMaxNumber);
std::unordered_set<int32_t> GenerateValues(int32_t currentNumber, int32_t baseAdd, int32_t numbersInARow,
                                            int32_t multiplier, int32_t maxNumber);
//Global variable to hold previously generated matrixes. This is for the sole purpose of easily
//demoing the advantage generating a matrix, with O(1) lookup for every evalutation after.
//
std::unordered_map< int32_t, std::unordered_map<int32_t, std::pair<int32_t, int32_t>>> generatedMatrixes;

int main()
{
    
    printf("Distance from center: %d \n", DistanceFromCenter(16, 50));
    printf("Distance from center: %d \n", DistanceFromCenter(32, 50));
    printf("Distance from center: %d \n", DistanceFromCenter(96, 100));
    printf("Distance from center: %d \n", DistanceFromCenter(12, 100));
    printf("Distance from center: %d \n", DistanceFromCenter(56, 100));
    printf("Distance from center: %d \n", DistanceFromCenter(526, 1000));
    printf("Distance from center: %d \n", DistanceFromCenter(9999, 10000));
    //This should take time to generate, however all subsequent calls to that size will generate in O(1) time.
    printf("Distance from center: %d \n", DistanceFromCenter(156733, 1000000));
    printf("Distance from center: %d \n", DistanceFromCenter(234544, 1000000));
    printf("Distance from center: %d \n", DistanceFromCenter(234253, 1000000));
    printf("Distance from center: %d \n", DistanceFromCenter(934235, 1000000));
    printf("Distance from center: %d \n", DistanceFromCenter(324254, 1000000));
    printf("Distance from center: %d \n", DistanceFromCenter(343453, 1000000));
    printf("Distance from center: %d \n", DistanceFromCenter(234, 1000000));
    printf("Distance from center: %d \n", DistanceFromCenter(32, 1000000));
}

//Top level function which calls for a matrix to be generated, and then caluculates the distance between the point and the center.
int32_t DistanceFromCenter(const int32_t iTargetValue, const int32_t iArraySize)
{
    if (generatedMatrixes.find(iArraySize) == generatedMatrixes.end())
        generatedMatrixes.insert(std::make_pair(iArraySize, GenerateMatrix(iArraySize)));

    return (abs(generatedMatrixes.find(iArraySize)->second.find(iTargetValue)->second.first)
        + abs(generatedMatrixes.find(iArraySize)->second.find(iTargetValue)->second.second));

}

//Generates and returns a map containing values and their associated cordinates within a matrix.
std::unordered_map<int32_t, std::pair<int32_t, int32_t>> GenerateMatrix(int32_t iMaxNumber)
{
    std::unordered_set<int32_t> xAdds = GenerateValues(2, 6, 1, 0, iMaxNumber);
    std::unordered_set<int32_t> yAdds = GenerateValues(3, 0, 1, 1, iMaxNumber);
    std::unordered_set<int32_t> xNegs = GenerateValues(4, 10, 2, 0, iMaxNumber);
    std::unordered_set<int32_t> yNegs = GenerateValues(6, 12, 2, 0, iMaxNumber);
    std::unordered_map<int32_t, std::pair<int32_t, int32_t>> umapGeneratedMatrix;

    int32_t xPosition = 0;
    int32_t yPosition = 0;

    for (int32_t value = 1; value <= iMaxNumber; value++)
    {
        if (xAdds.find(value) != xAdds.end())
            umapGeneratedMatrix.insert(std::make_pair(value, std::make_pair(++xPosition, yPosition)));

        else if (yAdds.find(value) != yAdds.end())
            umapGeneratedMatrix.insert(std::make_pair(value, std::make_pair(xPosition, ++yPosition)));

        else if (xNegs.find(value) != xNegs.end())
            umapGeneratedMatrix.insert(std::make_pair(value, std::make_pair(--xPosition, yPosition)));

        else if (yNegs.find(value) != yNegs.end())
            umapGeneratedMatrix.insert(std::make_pair(value, std::make_pair(xPosition, --yPosition)));

        else
            umapGeneratedMatrix.insert(std::make_pair(value, std::make_pair(xPosition, yPosition)));

    }

    return umapGeneratedMatrix;
}

std::unordered_set<int32_t> GenerateValues(int32_t iCurrentNumber, const int32_t iBaseAdd, int32_t iNumbersInARow,
                                            int32_t iMultiplier, int32_t iMaxNumber)
{
    int32_t addedNumber = 0;
    std::unordered_set<int> output;

    while (iCurrentNumber < iMaxNumber)
    {
        addedNumber = iCurrentNumber;
        for (int32_t iCount = 0; iCount < iNumbersInARow; iCount++)
            output.insert(addedNumber++);

        iCurrentNumber += iBaseAdd + 8 * iMultiplier++;
        iNumbersInARow += 2;
    }
    return output;
}


