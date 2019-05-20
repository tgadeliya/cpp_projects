

void UpdateIfGreater(int first, int& second){
    if (first>second){
        second = first;
    }
}


int main(int argc, char const *argv[])
{
    const int a = 5;
    int b = 4;
    UpdateIfGreater(a,b);

    return 0;
}
