#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FIFO(vector<int> memory)
{
    int headPos;
    int headMovmentCount = 0;
    cout<<"please enter the head position:"<<endl;
    cin>>headPos;
    int previous = headPos;
    cout<<headPos<<" -> ";
    for(auto x:memory)
    {
        headMovmentCount += abs(x-previous);
        cout<<x;
        if(x!=memory.back())
            cout<<" -> ";
        previous = x;
    }
    cout<<"\nTotal head movements = "<<headMovmentCount<<endl;
    cout<<"average head movement = "<<(float)headMovmentCount/memory.size()<<endl;
}

void SCAN(vector<int> memory)
{
    int headPos, headDirection;
    sort(memory.begin(),memory.end());
    cout<<"please enter the head position:"<<endl;
    cin>>headPos;
    int headMovmentCount = 0;
    int previous = headPos;
    cout<<"please enter the head direction (1- upwards, 2- downwards):"<<endl;
    cin>>headDirection;
    cout<<headPos<<" -> ";
    if(headDirection==1)
    {
        for(auto i=memory.rbegin(); i!=memory.rend(); ++i)
        {
            if(*i<headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i<<" -> ";
                previous = *i;
            }
        }
        for(auto i=memory.begin(); i!=memory.end(); ++i)
        {
            if(*i>=headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i;
                if(*i!=memory.back())
                    cout<<" -> ";
                previous = *i;

            }
        }
    }
    if(headDirection==2)
    {
        for(auto i=memory.begin(); i!=memory.end(); ++i)
        {
            if(*i>=headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i<<" -> ";
                previous = *i;

            }
        }
        for(auto i=memory.rbegin(); i!=memory.rend(); ++i)
        {
            if(*i<headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i;
                if(*i!=memory.front())
                    cout<<" -> ";
                previous = *i;
            }
        }
    }

    cout<<"\nTotal head movements = "<<headMovmentCount<<endl;
    cout<<"average head movement = "<<(float)headMovmentCount/memory.size()<<endl;
}

void CSCAN(vector<int> memory)
{
    int headPos, headDirection;
    sort(memory.begin(),memory.end());
    cout<<"please enter the head position:"<<endl;
    cin>>headPos;
    int headMovmentCount = 0;
    int previous = headPos;
    cout<<"please enter the head direction (1- upwards, 2- downwards):"<<endl;
    cin>>headDirection;
    cout<<headPos<<" -> ";
    if(headDirection==1)
    {
        for(auto i=memory.rbegin(); i!=memory.rend(); ++i)
        {
            if(*i<headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i<<" -> ";
                previous = *i;
            }
        }
        for(auto i=memory.rbegin(); i!=memory.rend(); ++i)
        {
            if(*i>=headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i;
                cout<<" -> ";
                previous = *i;

            }
        }
    }
    if(headDirection==2)
    {
        for(auto i=memory.begin(); i!=memory.end(); ++i)
        {
            if(*i>=headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i<<" -> ";
                previous = *i;

            }
        }
        for(auto i=memory.begin(); i!=memory.end(); ++i)
        {
            if(*i<headPos)
            {
                headMovmentCount += abs(*i-previous);
                cout<<*i;
                cout<<" -> ";
                previous = *i;
            }
        }
    }

    cout<<"\nTotal head movements = "<<headMovmentCount<<endl;
    cout<<"average head movement = "<<(float)headMovmentCount/memory.size()<<endl;
}

int main()
{
    int memorySpace;
    int requests;
    int method;
    vector<int> memory;
    cout<<"please select method (1- FIFO, 2- SCAN, 3- C-SCAN):"<<endl;
    cin>>method;
    cout<<"please enter disk space:"<<endl;
    cin>>memorySpace;
    cout<<"please number of entries:"<<endl;
    cin>>requests;
    cout<<"please enter questions:"<<endl;
    for(int i = 0; i<requests; i++)
    {
        int temp;
        cin>>temp;
        memory.push_back(temp);
    }
    switch(method)
    {
    case 1:
        FIFO(memory);
        break;
    case 2:
        SCAN(memory);
        break;
    case 3:
        CSCAN(memory);
        break;
    }

}
