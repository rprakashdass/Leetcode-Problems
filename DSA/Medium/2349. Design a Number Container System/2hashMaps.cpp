class NumberContainers {
public:
    map<int, set<int>> elements;
    map<int, int> indexes;
    NumberContainers() { }
    void change(int index, int number) {
        if(indexes.find(index) != indexes.end()){
            if(indexes[index] != number){
                int num = indexes[index];
                elements[num].erase(index);
                if(elements[num].empty()) elements.erase(num );
            }
        }
        elements[number].insert(index);
        indexes[index] = number;
    }
    int find(int number) {
        if(elements.find(number) == elements.end()) return -1;
        return *(elements[number].begin());
    }
};

// if(container.find(number) == container.end()) return -1;
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
**/
