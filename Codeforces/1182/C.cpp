#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

// Typedef
typedef std::pair<std::string, std::string> strduo;

// Vowel related
bool isVowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int vowelCount(std::string &word){
	int count = 0;
	for(auto ch: word) if(isVowel(ch)) count++;
	return count;
}
char lastVowel(std::string &word){
	for(int i=word.length()-1; i>=0; i--){
		if(isVowel(word[i])) return word[i];
	} throw "No vowels";
}

int main(void){
	
	// Get input
	int n; std::cin >> n;
	std::vector<std::string> totalwords;
	std::map<int, std::map<char, std::vector<std::string>>> strings_by_vowels;
	for(int i=0; i<n; i++){
		std::string word; std::cin >> word;
		totalwords.push_back(word);
		int vowelcount = vowelCount(word);
		char lastvowel = lastVowel(word);
		strings_by_vowels[vowelcount][lastvowel].push_back(word);
	}
	
	/*for(auto it: strings_by_vowels){
		printf("Vowel count %2d:\n", it.first);
		for(auto it2: it.second){
			printf("  %c: ", it2.first);
			for(auto it3: it2.second) printf("%s ", it3.c_str()); printf("\n");
		}
	}
	printf("===============\n");*/
	
	// Construct duos; Complete: SameCount+SameLast, Semicomplete: SameCount
	std::vector<strduo> complete_duos, semicomplete_duos;
	for(auto &same_counts: strings_by_vowels){
		
		// Complete duos
		for(auto &same_lasts: same_counts.second){
			while(same_lasts.second.size() >= 2){
				std::string firstline = same_lasts.second.back();
				same_lasts.second.pop_back();
				std::string secondline = same_lasts.second.back();
				same_lasts.second.pop_back();
				complete_duos.push_back({firstline, secondline});
			}
		}
		
		// Semicomplete duos
		std::vector<std::string> remainings;
		for(auto &same_lasts: same_counts.second){
			for(auto &word: same_lasts.second) remainings.push_back(word);
			same_lasts.second.clear();
		}
		while(remainings.size() >= 2){
			std::string firstline = remainings.back(); remainings.pop_back();
			std::string secondline = remainings.back(); remainings.pop_back();
			semicomplete_duos.push_back({firstline, secondline});
		}
	}
	
	// Construct lyrics
	std::vector<strduo> wholeLyric;
	while(!semicomplete_duos.empty() && !complete_duos.empty()){
		strduo semicomplete_duo = semicomplete_duos.back();
		semicomplete_duos.pop_back();
		strduo complete_duo = complete_duos.back();
		complete_duos.pop_back();
		wholeLyric.push_back({semicomplete_duo.first, complete_duo.first});
		wholeLyric.push_back({semicomplete_duo.second, complete_duo.second});
	}
	while(complete_duos.size() >= 2){
		strduo complete_duo1 = complete_duos.back(); complete_duos.pop_back();
		strduo complete_duo2 = complete_duos.back(); complete_duos.pop_back();
		wholeLyric.push_back({complete_duo1.first, complete_duo2.first});
		wholeLyric.push_back({complete_duo1.second, complete_duo2.second});
	}
	
	// Print
	std::cout << wholeLyric.size() / 2 << '\n';
	for(strduo &lyric: wholeLyric) std::cout << lyric.first << ' ' << lyric.second << '\n';
	return 0;
}