#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        QuickSort(arr, low, p);
        QuickSort(arr, p + 1, high);
    }
}

void QuickSortR(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int random = rand() % (high - low) + low;
        swap(arr[random], arr[low]);
        int p = partition(arr, low, high);
        QuickSortR(arr, low, p);
        QuickSortR(arr, p + 1, high);
    }
}

int main()
{
    vector<int> x = {10, 12, 15, 20, 1, 4, 17, 16, 11};
    int low = 0;
    int high = x.size();
    x.push_back(1e9);
    QuickSort(x, low, high);
    for (auto i : x)
        cout << i << " ";
    cout << endl;

    int random = rand() % (high - low + 1) + low;
    cout << random << endl;

    x = {10, 12, 15, 20, 1, 4, 17, 16, 11};
    x.push_back(1e9);
    QuickSortR(x, low, high);
    for (auto i : x)
        cout << i << " ";
    cout << endl;

    return 0;
}
