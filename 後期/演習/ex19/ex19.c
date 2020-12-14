/* 上級CプログラミングB 出題日：2020/12/14
   3I ○番 氏名 提出日：忘れずに記入！！ */
/* ファイル名：ex19.c
   演習 二分探索木のノードの探索，挿入用の関数の作成
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *root = NULL;

struct Node *nodeAdd (struct Node *p, int data){
  // 設問：挿入用関数の作成
  if (){



  }else{
    if () {

    }else if () {

    }else{

    }
  }
  return p;
}

void nodeSearch (struct Node *p, int data){
  // 設問：探索用関数の作成
  if (){

  }else{
    if ()

    else if ()

    else

  }
}

void PrintTree(struct Node *p){
  if (p!=NULL){
    PrintTree(p->left, i);
    printf("%d\n", p->data);
    PrintTree(p->right, i);
  }
}

int main(){
  int i;
  int a[10] = {21, 49, 35, 15, 77, 92, 93, 86, 83, 10};

  // 設問：順に挿入
  for(i=0; i<10; i++){
    root = ;
  }
  // 設問：通りがけ順で出力

  // 設問：35 を探索

  // 設問：34 を探索


  return 0;
}

/* 出力結果の貼り付け */
