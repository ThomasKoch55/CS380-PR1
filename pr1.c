#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>




int ratio(char **argv)
{
    char *filename = argv[1];
    int labelnum = atoi(argv[2]); //converting labelnumstring to int
    char currentline[4096];
    int linelength; 
    char *result;

    //Histogram variables
    int ten = 0;
    int twenty = 0;
    int thirty = 0;
    int fourty = 0;
    int fifty = 0;
    int sixty = 0;
    int seventy = 0;
    int eighty = 0;
    int ninety = 0;
    int hundred = 0;
    int fhundred = 0;
    


    
    FILE *infile;
    FILE *outfile;
    infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("Unable to open file %s.\n", filename);
        exit(1);
    }
    
    
    
    while (1)
    {
        
        result = fgets(currentline, (sizeof(currentline)+1), infile);
        if (result == NULL)
        {
            break;
        } 
        
        
        linelength = strlen(currentline) - 1;

        int i;
        double digitcount = 0;
        double labellength = 0;
        int pdcount = 0;
        double currratio = 0; 
        for (i = 0; i < linelength + 1; i++)
        {
            labellength += 1;

            if ( isdigit(currentline[i]) )
            {
                digitcount += 1;
            }

            if (currentline[i] == '.')
            {
                labellength -= 1;
                pdcount += 1;
                if (pdcount > labelnum)
                {
                    break;
                }
                else
                {
                    currratio = ((digitcount / labellength) * 100);

                    //Assigning to correct Histogram value

                    if (currratio < 10)
                    {
                        ten += 1;
                    }
                    else if (currratio < 20)
                    {
                        twenty += 1;
                    }
                    else if (currratio < 30)
                    {
                        thirty += 1;
                    }
                    else if (currratio < 40)
                    {
                        fourty += 1;
                    }
                    else if (currratio < 50)
                    {
                        fifty += 1;
                    }
                    else if (currratio < 60)
                    {
                        sixty += 1;
                    }
                    else if (currratio < 70)
                    {
                        seventy += 1;
                    }
                    else if (currratio < 80)
                    {
                        eighty += 1;
                    }
                    else if (currratio < 90)
                    {
                        ninety += 1;
                    }
                    else if (currratio < 100 )
                    {
                        hundred += 1;
                    }
                    else if (currratio == 100)
                    {
                        fhundred += 1;
                    }
                }
                labellength = 0;
                digitcount = 0;
            }
            if ((currentline[i] == '\n') && (pdcount<labelnum))
            {
                labellength -= 1;
                currratio = ((digitcount / labellength) * 100);

                    //Assigning to correct Histogram value

                    if (currratio < 10)
                    {
                        ten += 1;
                    }
                    else if (currratio < 20)
                    {
                        twenty += 1;
                    }
                    else if (currratio < 30)
                    {
                        thirty += 1;
                    }
                    else if (currratio < 40)
                    {
                        fourty += 1;
                    }
                    else if (currratio < 50)
                    {
                        fifty += 1;
                    }
                    else if (currratio < 60)
                    {
                        sixty += 1;
                    }
                    else if (currratio < 70)
                    {
                        seventy += 1;
                    }
                    else if (currratio < 80)
                    {
                        eighty += 1;
                    }
                    else if (currratio < 90)
                    {
                        ninety += 1;
                    }
                    else if (currratio < 100 )
                    {
                        hundred += 1;
                    }
                    else if (currratio == 100)
                    {
                        fhundred += 1;
                    }
                    labellength = 0;
                    digitcount = 0;


            }
        }
        
    }

    //Create the file

    char newfilename[strlen(filename)];
    strcpy(newfilename, filename);
    int i;
    for (i = strlen(newfilename); i >= 0 ; i--)
    {
        if (newfilename[i] == '.')
        {
            newfilename[i] = '\0';
            break;
        }
        
    }
    


    char fname[256];
    sprintf(fname, "%s_%d_hist.txt", newfilename, labelnum);


    outfile = fopen(fname, "w"); //placeholder name
    if (outfile == NULL) 
    {
        printf("Unable to open outfile: %s\n", fname);
        exit(1);
    }
    
    fprintf(outfile, "[0-10): %d\n [10-20): %d\n [20-30): %d\n [30-40): %d\n [40-50): %d\n [50-60): %d\n [60-70): %d\n [70-80): %d\n [80-90): %d\n [90-100): %d\n [100]: %d\n", ten,twenty,thirty,fourty,fifty,sixty,seventy,eighty,ninety,hundred,fhundred);

    
    // test print
    //printf("filename: %s\nlabelnum: %d\n%d\n", filename, labelnum, (labelnum + 1));
    fclose(infile);
    fclose(outfile);
    return 1;
}




int main(int argc, char **argv)
{

    if (argc != 3)
    {
        printf("Please include a text file as your first argument and a number that specifies a label number as your second.\n");
        exit(1);
    }
    
    ratio(argv);

    return 0;
}



