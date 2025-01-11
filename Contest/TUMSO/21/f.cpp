#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) อ่าน n และอาร์เรย์ a
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // เซตของตำแหน่ง b ที่ยังเป็นไปได้ (initially ทั้งหมด)
    vector<bool> possible(n+1, true);
    int countPossible = n;  // จำนวนที่ยังเป็นไปได้

    // เราจะทำอย่างมาก 50 queries
    for(int queryCount = 0; queryCount < 50; queryCount++){
        // ถ้าเหลือความเป็นไปได้แค่ 1 ตัว ก็จบได้เลย
        if(countPossible == 1){
            // หา index ที่ยัง true
            int answerIndex = -1;
            for(int i = 1; i <= n; i++){
                if(possible[i]){
                    answerIndex = i;
                    break;
                }
            }
            // สั่งตอบ
            cout << "answer " << answerIndex << "\n";
            fflush(stdout);
            return 0;
        }

        // สร้าง mapping: mapValue[v] = list ของ i ที่ a[i] = v (และ i ยัง possible)
        // พร้อมนับความถี่ในแต่ละ v (คือ U ในแนวคิด)
        unordered_map<int, vector<int>> preimage;
        preimage.reserve(countPossible);
        for(int i = 1; i <= n; i++){
            if(possible[i]){
                preimage[a[i]].push_back(i);
            }
        }

        vector<pair<int,int>> freq; 
        freq.reserve(preimage.size());
        for(auto &kv : preimage){
            freq.push_back({kv.first, (int)kv.second.size()});
        }
        sort(freq.begin(), freq.end(), [&](auto &x, auto &y){
            return x.second > y.second;
        });

        int halfSize = countPossible / 2;
        int runningSum = 0;
        unordered_set<int> chosen;
        for (auto &p : freq) {
            if(runningSum + p.second <= halfSize){
                runningSum += p.second;
                chosen.insert(p.first);
            }
        }

        vector<int> S;
        S.reserve(runningSum);
        for(auto &val : chosen){
            for(int i : preimage[val]){
                S.push_back(i);
            }
        }

        cout << "ask " << S.size();
        for(int i : S){
            cout << " " << i;
        }
        cout << "\n";
        fflush(stdout);

        string response;
        cin >> response;

        vector<bool> newPossible(n+1, false);
        int newCount = 0;
        if(response == "yes"){
            for(int i : S){
                newPossible[a[i]] = true;
            }
            newCount = runningSum;
        }
        else {
            newCount = 0;
            for(int i = 1; i <= n; i++){
                if(possible[i]){
                    if(!newPossible[a[i]]){
                    }
                    if(chosen.find(a[i]) == chosen.end()){
                        newPossible[a[i]] = true;
                    }
                }
            }
            for(int v = 1; v <= n; v++){
                if(newPossible[v]) newCount++;
            }
        }

        possible = move(newPossible);
        countPossible = newCount;
    }

    int answerIndex = -1;
    for(int i = 1; i <= n; i++){
        if(possible[i]){
            answerIndex = i;
            break;
        }
    }
    cout << "answer " << answerIndex << "\n";
    fflush(stdout);

    return 0;
}