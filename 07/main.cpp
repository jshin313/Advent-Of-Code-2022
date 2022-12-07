#include <bits/stdc++.h>

using namespace std;

// Directories are also files
class File
{
    public:
        int size; 
        File* parent;
        unordered_map<string, File *> children; 
        string name;
        bool is_dir;

        File() {
            this->size = 0;
        }

        File(string name) {
            this->name = name;
            this->size = 0;
        }

        void update_sizes() {
            if (children.empty()) {
                is_dir = false;
                return;
            }

            for (auto it = children.cbegin(); it != children.cend(); it++) {
                it->second->update_sizes();
                /* cout << it->second->name << ": " << it->second->size << endl; */

                if (it->second->is_dir) {
                    this->size+=it->second->size;
                }
            }
        }

        int find_sum_of_less_than_100k(File* root) {
            if (children.empty()) {
                return 0;
            }

            int sum = 0;
            if (this->size <= 100000 && this!=root) {
                sum+=size;
            }

            for (auto it = children.cbegin(); it != children.cend(); it++) {
                sum += it->second->find_sum_of_less_than_100k(root);
            }

            return sum;
        }

        int get_smallest_dir_to_delete(int space_needed) {
            int min_size = this->size;
            /* cout << this->name <<": " <<is_dir << endl; */
            if (this->size < space_needed || !(this->is_dir)) {
                return INT_MAX;
            } else {
                /* cout << this->name <<": " <<min_size << endl; */
                for (auto it = children.cbegin(); it != children.cend(); it++) {
                    int smallest_children_size = it->second->get_smallest_dir_to_delete(space_needed);
                    min_size = min(smallest_children_size, min_size);
                }
            }

            return min_size;
        }
};

File* create_tree_from_input() {
    string s;

    // Assume first command is cd <dir_name>
    File* root = new File();
    cin >> s >> s >> root->name;
    root->is_dir = true;

    File* current_dir = root;

    while (cin >> s) {
        if (s == "$") {
            string command, argument;
            cin >> command;
            if (command == "ls") {

            } else if (command == "cd") {
                cin >> argument;
                
                // Switch to where the cd <argument> directory
                if (argument == "..") {
                    current_dir = current_dir->parent;
                } else {
                    current_dir = current_dir->children[argument];
                }
            }
        } else {
            string file_name; cin >> file_name;

            if (current_dir->children.find(file_name) == current_dir -> children.end()) {
                
                // Add new file to parent
                File* file = new File(file_name);
                file->parent=current_dir;
                current_dir->children[file_name] = file;

                file->is_dir = (s == "dir");
                if (!file->is_dir) {
                    file->size = std::stoi(s);
                    // Update parent file_size
                    current_dir->size += file->size;

                }
            }
        }
    }

    // Update directory sizes
    root->update_sizes();

    return root;

}

void part1(File* root) {
    cout << root->find_sum_of_less_than_100k(root) << endl;
}

void part2(File* root, unsigned int total_space, unsigned int update_size) {
    int space_needed = update_size - (total_space - root->size);
    cout << root->get_smallest_dir_to_delete(space_needed) << endl;

}

int main(int argc, char **argv)
{
    string s;
    
    freopen("input.txt", "r", stdin);
    /* freopen("test.txt", "r", stdin); */

    unsigned int TOTAL_DISK_SPACE = 70000000;
    unsigned int UPDATE_SIZE = 30000000;


    File* root = create_tree_from_input();
    part1(root);
    part2(root, TOTAL_DISK_SPACE, UPDATE_SIZE);

}
