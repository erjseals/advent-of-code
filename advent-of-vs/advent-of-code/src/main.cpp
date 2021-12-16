#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <set>

int largerThanPrevious();

/*******************************************************************************************************/

int main(int argc, char* argv[])
{
    if (argc != 1)
    {
        std::cerr << "Incorrect number of inputs!" << std::endl;
    }
    else
    {
        std::cout << largerThanPrevious() << std::endl;
    }
}

/*******************************************************************************************************/


int largerThanPrevious()
{
    std::vector<int> vecRaw, vecSlide;

    std::ifstream fileStream;
    fileStream.open("res/day1p1.txt");

    // Read file, put data into vecRaw
    if (fileStream.is_open())
    {
        std::string input;
        while (fileStream >> input)
        {
            vecRaw.push_back(std::stoi(input));
        }
    }
    else
    {
        std::cerr << "Failed to open file!" << std::endl;
        return -1;
    }

    // Non-sliding window
    int count = 0;
    for (size_t i = 1; i < vecRaw.size(); i++)
    {
        if (vecRaw[i] > vecRaw[i - 1])
        {
            count++;
        }
        std::cout << "prev_elem: " << vecRaw[i - 1] << " elem: " << vecRaw[i] << " count: " << count << std::endl;
    }
    return count;

    // Now use a sliding window to smooth out numbers
    // Not checking size of file, better be at least 3 lines

    int index = 0, sum = 0;
    int array[3];

    array[0] = vecRaw[0];
    array[1] = vecRaw[1];
    array[2] = vecRaw[2];

    sum = (array[0] + array[1] + array[2]);
    vecSlide.push_back(sum);

    for (size_t i = 3; i < vecRaw.size(); i++)
    {
        array[index % 3] = vecRaw[i];
        sum = (array[0] + array[1] + array[2]);
        vecSlide.push_back(sum);
        index++;
    }

    count = 0;
    for (size_t i = 1; i < vecSlide.size(); i++)
    {
        if (vecSlide[i] > vecSlide[i - 1])
        {
            count++;
        }
    }

    return count;
}
