#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

struct Page {
    int id;
    string path;
    int counter;
    Page(int id, string path) {  // this is constructor, use to create a new struct
        this->id = id;
        this->path = path;
        counter = 0;
    };
};

// This function can facilitate sorting
bool operator<(const Page & a, const Page & b) { 
    return (a.id < b.id);
}

vector<Page> pages;

struct User {
    int id;
    vector<string> visits;
    User(int id) {
        this->id = id;
    };
    void add_visit(int page_id) {
        // To be implemented
        // add path path to visit if same path id
        for (int i=0;i<pages.size();i++){
            if (pages[i].id == page_id){
                visits.push_back(pages[i].path);
            }
        }
    };
    int size() const {
        return visits.size();
    };
    void print_visits() {
        // To be implemented
        // print all the visit for the top 5 users
        sort(visits.begin(), visits.end());
        for (int i=0;i<visits.size();i++){
            cout << "- " << visits[i] << endl;
        }
    }
};

vector<User> users;

// Please implement the following function to facilitate the sorting of users (done!)
bool operator<(const User & a, const User & b) {
    // sort user by no. of website visited, followed by id
    if (a.visits.size() != b.visits.size()){
        return (a.visits.size() > b.visits.size());}
    else { // same visit size, so compare id
        return (a.id < b.id);}
}

// Please implement the following function (done!)
void add_page(const Page& p) {
    // add pages to struct
    pages.push_back(p);
}

// Please implement the following function (done!)
bool cmp_page_count(const Page & a, const Page & b) {
    // sort pages by counter, followed by path path in a-z
    if (a.counter != b.counter) {
        return (a.counter > b.counter);}
    else { // same count, so compare path
        return (a.path < b.path);}
}

// Please implement the following function (done!)
void print_pages(int number) {
    // print top 5 pages
    for (int i=0;i<number;i++){
        cout << pages[i].counter << ":" << pages[i].path << endl;
    } 
}

// Please implement the following function (done!)
void add_user(User u) {
    // add user to struct
    users.push_back(u);
}

// Please implement the following function
void add_visit(int page_id) {
    // add the visited page id
    users[users.size()-1].add_visit(page_id); 
}

// Please implement the following function (done!)
void print_users(int number) {
    // print the top 5 users and te pages visited
    for (int i=0;i<number;i++){
        cout << users[i].size() << ":" << users[i].id << endl;
        users[i].print_visits();
    }
}

int main() {

    string type;
    while(cin >> type) {
        if(type == "USER") {
          int user_id;
          cin >> user_id;
          User u(user_id);
          add_user(u);
        } else if(type == "PAGE") {
          int page_id;
          string page_path;
          cin >> page_id;
          cin >> page_path;
          Page p(page_id, page_path);
          add_page(p);
        } else if(type == "VISIT") {
          int page_id;
          cin >> page_id;
          Page p(page_id, "");
          sort(pages.begin(), pages.end()); // This line is extra, idk why :(
          vector<Page>::iterator iter = lower_bound(pages.begin(), pages.end(), p);
          if(iter->id == p.id) {
            iter->counter++;
          }
          add_visit(p.id);
        }
    }
    sort(pages.begin(), pages.end(), cmp_page_count);
    cout << "*** 5 most popular pages ***" << endl;
    print_pages(5);
    sort(pages.begin(), pages.end());

    sort(users.begin(), users.end());
    cout << "*** 5 most active users ***" << endl;
    print_users(5);

    return 0;

}