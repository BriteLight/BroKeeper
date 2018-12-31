#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_RECORDS_ROWS = 7;
const int MAX_FIGURES_COLS  = 5;
typedef string StoreName[MAX_RECORDS_ROWS];
typedef float StoreTotals[MAX_RECORDS_ROWS];
typedef float StoreSales[MAX_RECORDS_ROWS][MAX_FIGURES_COLS];

void Get_store_data(StoreName&, StoreSales&);
void Compute_sales_total(StoreName&, StoreSales&, StoreTotals&, float&);
void Display_Store_Data(StoreName&, StoreSales&, StoreTotals&, float&);

void Get_store_data(StoreName& sto, StoreSales& sales)
{
      ifstream inFile;
      inFile.open("inFile.txt");
      int record=0;
      while ( !inFile.eof() )
      {
              inFile >> sto[record];
              for (int i=0;i<MAX_FIGURES_COLS;i++)
              {
                      inFile  >> sales[record][i];
              }
              record++;
      }
      inFile.close();
}

void Compute_sales_total(StoreSales& sales, StoreTotals& sto_total, float& grand_tot)
{
        grand_tot = 0;
        for(int i=0;i<MAX_RECORDS_ROWS;i++)
        {
              sto_total[i] = 0;
              for(int j=0;j<MAX_FIGURES_COLS;j++)
              {
                      sto_total[i] = sto_total[i] + sales[i][j];
              }
              grand_tot = grand_tot + sto_total[i];
        }
}

void Display_Store_Data(StoreName& sto, StoreSales& sales, StoreTotals& sto_total, float& grand_tot)
{
        cout << "Store sales for late summer and fall" << endl;
        cout << "Store:\t\t\t\t\t   Jun\tJul\tAug\tSep\tOct\t\tStore Totals" << endl;
        for(int i=0;i=MAX_RECORDS_ROWS;i++)
        {
                cout << sto[i] << "      \t\t\t";
                for(int j=0;j<MAX_FIGURES_COLS;j++)
                {
                        cout << sales[i][j] << "\t";
                }
                cout << "\t" << sto_total[i] << endl;
        }
        cout << "Grand Total:\t\t\t\t\t\t\t\t\t\t" << grand_tot << endl << endl;
}

int main()
{
      StoreName sto;
      StoreSales sales;
      StoreTotals sto_total;
      float grand_tot=0;
      Get_store_data(sto, sales);
      Compute_sales_total(sales, sto_total, grand_tot);
      Display_Store_Data(sto, sales, sto_total, grand_tot);
      return 0;
}
