Strong Password Checker

A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

int strongPasswordChecker(char* s) {    }

Solution:

Let's crate the function passwordLength() that returns 1 or 0 depending on if the password meets the first condition.

passwordLength(String password){
  if (password.length < 6 or password.length > 20){
    return 1;
  }else{
    return 0;
  }
}

For the second condition, let's create the function that checks how many points of the second condition are not met.

passwordContains(String password){
  char[] upperArray = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
  char[] lowerArray = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};
  int[] digitArray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int changes = 0;

  For (each a in upperArray){
    if (password.contains(a)){
      break;
    }else{
      changes = changes + 1;
    }
  }
  For (each b in lowerArray){
    if (password.contains(b)){
      break;
    }else{
      changes = changes + 1;
    }
  }
  For (each c in digitArray){
    if (password.contains(c)){
      break;
    }else{
      changes = changes + 1;
    }
  }

  return changes;
}

And for the third condition let's create another function that returns the amount of times that the third condition is broken

passwordRepeat(String password){

  int changes = 0;

  for(i = 0 to password.length - 3){
    if (password[i] == password[i+1] && password[i] == password[i+2]){
      changes = changes + 1;
      if(i < passwordLength-6){
        i = i + 3;
      }
    }
  }
  return changes;
}

Finally we have to create the function strongPasswordChecker() that sums all the changes made by the other functions and return the minimum amount of changes in the password to make it a good password.

strongPasswordChecker(String s){
  int changes = 0;
  changes = changes + passwordLength(s);
  changes = changes + passwordContains(s);
  changes = changes + passwordRepeat(s);

  return changes;
}
