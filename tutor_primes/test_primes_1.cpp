#include <iostream>
#include <vector>
#include <string>

using namespace std;


// check if given number is prime or not
bool isPrime(int num){
  // start with cornercases
  if (num <= 1)
    return false;

  // check from 2 above
  for (int i=2; i<num; i++)
  {
    if (num % i == 0)
      return false;
  }

  // otherwise, it is a PRIME
  return true;
}

// split
vector<string> splitByDelim(string const &str, const char delim){
    // init
	size_t start;
	size_t end = 0;

    vector<string> out;

    // find the delim, and split
	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}

    return out;
}

void fizzBuzz(vector<int> nums, vector<string> names, int denom){
    
    bool prime_denom = isPrime(denom);
    bool non_divideable = true;

    // [fixed] now correct division
    for (int i=0; i<nums.size(); i++){
        if (nums[i] % denom != 0) 
            non_divideable = true;
        else{
            non_divideable = false;
            break;
        }
    }

    // check 1st - criteria -- if all nums can't be divided by the denom
    if (non_divideable && prime_denom){
        cout << "prime" << endl;
        return;
    }
    else if (non_divideable && !prime_denom){
        cout << denom;
        return;
    }

    // check 2nd - criteria -- if any nums divideable by the denom
    if (!non_divideable){
        for (auto &s:names)
            cout << s;
    }
}


int main(int argc, char *argv[]){

    // get denominator
    char *denominator = argv[argc-1];

    // split all pairs, get numbers and strings
    vector<string> pairs;
    vector<string> pairs_unpaired;
    vector<int> numbers;
    vector<string> names;

    for (int i = 1; i < argc-1; i++)
        pairs.push_back(argv[i]);

    // delimiter
    const char delim = ':';

    for (auto i = pairs.begin(); i != pairs.end(); i++)
    {
        cout << *i << endl;

        // [fixed], splitByDelim now return pairs instead of pass by reference
        pairs_unpaired = splitByDelim(*i, delim);

        // decode pairs_unpaired[0] to int
        // decode pairs_unpaired[1] to string
        numbers.push_back(stoi(pairs_unpaired[0]));
        names.push_back(pairs_unpaired[1]);
    }

    // fizzbuzz
    fizzBuzz(numbers, names, stoi(denominator));
    
    cout << endl;

    return 0;
}