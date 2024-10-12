#include <iostream>
using namespace std;
/**
 * Name: Conrad Sadler
 * Date:10/02/2024
 * Project description: DNA Analysis
 */

/**
 * Description: The function will determine whether a given character is a valid DNA base. The function does not print anything.
 * @param base The character to validate
 * @return The function should return true if the character is a valid base (A, C, G, or T)
 */
bool isValidBase(char base);

/**
 * Description: The function will determine whether a given string consists only of valid DNA bases. The function does not print anything.
 * This function uses isValidBase(char base).
 * @param strand The DNA strand to validate
 * @return The function should return true if the string is a valid DNA strand and false otherwise
 */
bool isValidStrand(string strand);

/**
 * Description: The function will find the similarity between two DNA strands. The function does not print anything.
 * @param strand1 The first DNA strand to compare
 * @param strand2 The second DNA strand to compare
 * @return The funcation returns the similarity score between the two strands, or zero if strand1 length != strand2 length
 */
double strandSimilarity(string strand1, string strand2);

/**
 * Description: The function will find the best similarity between two DNA strands. The function prints the best similarity score.
 * This function uses standSimilarity(string strand1, string strand2) function.
 * @param inputStrand The input DNA strand to be checked against the targetStrand
 * @param targetStrand The target DNA strand.
 * @return If the parameters are valid, returns an integer representing the starting index of the substring in the input strand there 
 * the best alignment with target strand occurs. Returns -1 if the input strand is shorter than the target strand. Also in this case 
 * the function prints out "Best similarity score: 0.0"
 */
int bestStrandMatch(string inputStrand, string targetStrand);

/**
 * Description: The function compares two DNA sequences to identify all types of mutations between them. It aligns the sequences based
 * on the best possible match and processes them character by character, printing out any mutations as they are detected.
 * If no mutations are found, the function outputs "No mutations found."
 * This function calls the bestStrandMatch(string inputStrand, string targetStrand) fuction.
 * @param inputStrand The input strand to be checked against the target
 * @param targetStrand The target strand
 * @return N/A
 */
void identifyMutations(string inputStrand, string targetStrand);

/**
 * Decription: The function will transcribe a DNA sequence to RNA and print the RNA sequence to the console. The funcation will replace 
 * all occurrences of 'T' with 'U'.
 * @param strand The DNA sequence to be transcribed.
 * @return N/A
 */
void transcribeDNAtoRNA(string strand);

/**
 * Description: The function will compute the reverse complement for a DNA sequence and print the result to the console.
 * 'A' is complemented by 'T'
 * 'T' is complemented by 'A'
 * 'C' is complemented by 'G'
 * 'G' is complemented by 'C'
 * @param strand The DNA sequence for which the reverse complement will be computed.
 * @return N/A
 */
void reverseComplement(string strand);

/**
 * Description: The function will print out complete reading frames. This function will identify frames that start with the 
 * character sequence 'ATG' and end with one of the stop character sequences('TAA', 'TAG', or 'TGA').
 * The function prints "No reading frames found" if no reading frames are found.
 * @param The DNA strand from which to extract reading frames.
 * @return N/A
 */
void getCodingFrames(string strand);

/**
 * Description: prints the menu for the user
 * @return N/A
 */
void outputMenu();

int main()
{
    int userChoice = 0;
    int result;
    double presiseResult;
    string strand1;
    string strand2;
    
    while(userChoice != 7)
    {
        outputMenu();  //outputs the user's options
        cin >> userChoice;
        while(userChoice < 1 || userChoice > 7)
        {
            cout << "Invalid input. Please select a valid option." << endl;
            outputMenu();
            cin >> userChoice;
        }
        switch(userChoice)
        {
            case 1:
                cout << "Enter the first DNA sequence:" << endl;
                cin >> strand1;

                while(!isValidStrand(strand1))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> strand1;
                }
                cout << "Enter the second DNA sequence:" << endl;
                cin >> strand2;

                while(!isValidStrand(strand2))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> strand2;
                }
                presiseResult = strandSimilarity(strand1, strand2);
                if(presiseResult == 0.0)
                {
                    cout << "Error: Input strands must be of the same length." << endl;
                }
                else
                {
                    cout << "Similarity score: " << presiseResult << endl;
                }
                break;
            case 2:
                cout << "Enter the first DNA sequence:" << endl;
                cin >> strand1;

                while(!isValidStrand(strand1))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> strand1;
                }
                cout << "Enter the second DNA sequence:" << endl;
                cin >> strand2;

                while(!isValidStrand(strand2))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> strand2;
                }
                result = bestStrandMatch(strand1,strand2);
                if(result == -1)
                {
                    //cout << "Error: Input strand must be longer than test strand." << endl;
                }
                break;
            case 3:
                cout << "Enter the first DNA sequence:" << endl;
                cin >> strand1;

                while(!isValidStrand(strand1))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> strand1;
                }
                cout << "Enter the second DNA sequence:" << endl;
                cin >> strand2;

                while(!isValidStrand(strand2))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> strand2;
                }
                identifyMutations(strand1, strand2);
                break;
            case 4:
                cout << "Enter the DNA sequence to be transcribed:" << endl;
                cin >> strand1;

                while(!isValidStrand(strand1))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the DNA sequence to be transcribed:" << endl;
                    cin >> strand1;
                }
                cout << "The transcribed DNA is: ";
                transcribeDNAtoRNA(strand1);
                break;
            case 5:
                cout << "Enter the DNA sequence:" << endl;
                cin >> strand1;

                while(!isValidStrand(strand1))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the DNA sequence:" << endl;
                    cin >> strand1;
                }
                cout << "The reverse complement is: ";
                reverseComplement(strand1);
                break;
            case 6:
                cout << "Enter the DNA sequence:" << endl;
                cin >> strand1;

                while(!isValidStrand(strand1))
                {
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                    cout << "Enter the DNA sequence:" << endl;
                    cin >> strand1;
                }
                cout << "The extracted reading frames are:" << endl;
                getCodingFrames(strand1);
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Unknown error" << endl;
        }
    }
    return 0;
}

bool isValidBase(char base)
{
    switch(base)
    {
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            return true;
        default:
            return false;
    }
}

bool isValidStrand(string strand)
{
   for(int i = 0; i < int(strand.length()); i++)
   {
        if(!isValidBase(strand[i]))
        {
            return false;
        }
   }
   return strand.length();
}

double strandSimilarity(string strand1, string strand2)
{
    if (strand1.length() != strand2.length())
    {
        return 0;
    }
    else
    {
        int num = 0;
        int count = 0;

        while(num < int(strand1.length()))
        {
            if(strand1[num] == strand2[num])
            {
                count++;
            }
            num++;
        }

        return double(count) / num;
    }

}

int bestStrandMatch(string inputStrand, string targetStrand)
{
    int bestStartIndex;
    double bestSimilarity;

    if(inputStrand.length() < targetStrand.length())
    {
        bestStartIndex = -1;
        
        cout << "Best similarity score: 0.0" << endl;
        return bestStartIndex;
    }
    else
    {
        bestStartIndex = 0;
        bestSimilarity = 0.0;
    }

    for(int i = 0; i+(targetStrand.length()-1) < inputStrand.length(); i++)
    {
        
        if(strandSimilarity(inputStrand.substr(i,targetStrand.length()),targetStrand)>bestSimilarity)
        {
            bestSimilarity = strandSimilarity(inputStrand.substr(i,targetStrand.length()),targetStrand);
            bestStartIndex = i;
        }
    }

    cout << "Best similarity score: " << bestSimilarity << endl;
    return bestStartIndex;
}

void identifyMutations(string inputStrand, string targetStrand)
{
    if(inputStrand == targetStrand)
    {
       cout << "Best similarity score: 1\nBest alignment index: 0\nNo mutations found." << endl;
    }
    else if(inputStrand.length() <= targetStrand.length())
    {
        int bestAlignment = bestStrandMatch(targetStrand,inputStrand);
        int smallerIndex;
        
        cout << "Best alignment index: " << bestAlignment << endl;

        for(int i = 0; i < int(targetStrand.length()); i++)
        {
            smallerIndex = (i - bestAlignment);
            if(i < bestAlignment)
            {
                cout << "Insertion at position " << i+1 << ": " << targetStrand[i] << " is inserted in target strand" << endl;
            }
            else if( i >= bestAlignment && smallerIndex < int(inputStrand.length()))
            {
                if(inputStrand[smallerIndex] != targetStrand[i])
                {
                    cout << "Substitution at position " << i+1 << ": " << inputStrand[smallerIndex] << " -> " << targetStrand[i] << endl;
                }
            }
            else
            {
                cout << "Insertion at position " << i+1 << ": " << targetStrand[i] << " is inserted in target strand" << endl;
            }
        }
    }
    else
    {
        int bestAlignment = bestStrandMatch(inputStrand,targetStrand);
        int smallerIndex;
        cout << "Best alignment index: " << bestAlignment << endl;

        for(int i = 0; i < int(inputStrand.length()); i++)
        {
            smallerIndex = (i - bestAlignment);
            if(i < bestAlignment)
            {
                cout << "Deletion at position " << i+1 << ": " << inputStrand[i] << " is deleted in target strand" << endl;
            }
            else if( i >= bestAlignment && smallerIndex < int(targetStrand.length()))
            {
                if(targetStrand[smallerIndex] != inputStrand[i])
                {
                    cout << "Substitution at position " << i+1 << ": " << inputStrand[i] << " -> " << targetStrand[smallerIndex] << endl;
                }
            }
            else
            {
                cout << "Deletion at position " << i+1 << ": " << inputStrand[i] << " is deleted in target strand" << endl;
            }
        }
    }
}

void transcribeDNAtoRNA(string strand)
{
    for(int i = 0; i < int(strand.length()); i++)
    {
        if(strand[i] == 'T')
        {
            strand = strand.substr(0,i) + 'U' + strand.substr(i+1);
        }
    }
    cout << strand << endl;
}

void reverseComplement(string strand)
{
    for(int i = 0; i < int(strand.length()/2); i++)
    {
            /**
             * This following line of code is complicated but here is the jist:
             * strand = all chars before index i + the ith char from the back of the string + all chars after index i but before the ith char from the back of the string + char at index i + all characters after
             * Visual:
             *  Ex.reverseing "ABC"
             *  Key: _ represents before and after
             *       * represents the middle that stays constant during swap
             *  strand original = ABC
             *  strand = _ C * A _
             *  strand after first swap = CBA
             */
        strand = strand.substr(0,i) + strand[(strand.length()-1)-i] + strand.substr(i+1,(strand.length()-1)-((2*i)+1)) + strand[i] + strand.substr(i+2+(strand.length()-1)-((2*i)+1));
    }
    for(int i = 0; i < int(strand.length()); i++)
    {
        switch(strand[i])
        {
            case 'A':
                strand = strand.substr(0,i)+'T'+strand.substr(i+1);
                break;
            case 'T':
                strand = strand.substr(0,i)+'A'+strand.substr(i+1);
                break;
            case 'C':
                strand = strand.substr(0,i)+'G'+strand.substr(i+1);
                break;
            case 'G':
                strand = strand.substr(0,i)+'C'+strand.substr(i+1);
                break;
            default:
                break;
        }
    }
    cout << strand << endl;
}

void getCodingFrames(string strand)
{
    string startAndEndCondons = "";
    string recordFrame = "";
    bool start = false;  //if start is false, the characters from the strand are not being recorded in a coding frame becasue startAndEndCondons does not equal "ATG"
    bool foundFrame = false;  //if this is made true, the function will not print "No reading frames found."
    bool holdStartAndEndCondons = false;  //this will let characters from strand be added to startAndEndCondons if the next three characters in the strand are a start condon or end condon

    for(int i = 0; i < int(strand.length()); i++)
    {
       if (holdStartAndEndCondons == false)
       {
            if((strand.substr(i,3)) == "ATG" && start == false)
            {
                holdStartAndEndCondons = true;
            }
            else if(((strand.substr(i,3)) == "TAA" || (strand.substr(i,3)) == "TAG" || (strand.substr(i,3)) == "TGA") && start == true )
            {
                holdStartAndEndCondons = true;
            }
       }
       if(holdStartAndEndCondons == true)
       {
          startAndEndCondons += strand[i];  
       }

        if(startAndEndCondons == "ATG" && start == false)
        {
            start = true;
            holdStartAndEndCondons = false;
            recordFrame = startAndEndCondons;
            startAndEndCondons = "";
        }
        else if(start == true)
        {
            recordFrame+=strand[i];
        }

        if(startAndEndCondons == "TAA" || startAndEndCondons == "TAG" || startAndEndCondons == "TGA")
        {
            
            if((recordFrame.length() - 6) % 3 == 0)  //if the inside is divisable by three, then it is a valid codon
            {
                start = false;
                foundFrame = true;
                cout << recordFrame << endl;
                recordFrame = "";
            }
            holdStartAndEndCondons = false;
            startAndEndCondons = "";
            if(strand.substr(5,3) == "TAA")
            {
              start = false;
              recordFrame = "";
            }
        }
    }
    if(foundFrame == false)
    {
        cout << "No reading frames found." << endl;
    }
}

void outputMenu()
{
    cout << "--- DNA Analysis Menu ---" << endl;
    cout << "1. Calculate the similarity between two sequences of the same length" << endl;
    cout << "2. Calculate the best similarity between two sequences of either equal or unequal length" << endl;
    cout << "3. Identify mutations" << endl;
    cout << "4. Transcribe DNA to RNA" << endl;
    cout << "5. Find the reverse complement of a DNA sequence" << endl;
    cout << "6. Extract coding frames" << endl;
    cout << "7. Exit" << endl;
    cout << "Please enter your choice (1 - 7):" << endl;
}