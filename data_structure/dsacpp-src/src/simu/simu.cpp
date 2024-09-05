/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "simu.h"

void simulate( Rank wins, Rank servTime ) { //��ָ����������������ʱ��ģ������ҵ��
   Queue<Customer>* window = new Queue<Customer>[wins]; //Ϊÿһ���ڴ���һ������
   for ( Rank now = 0; now < servTime; now++ ) { //���°�֮ǰ��ÿ��һ����λʱ��
      if ( rand() % ( 1 + wins ) ) { //�¹˿���wins/(wins + 1)�ĸ��ʵ���
         Customer c ; c.time = 1 + rand() % 98; //�¹˿͵������ʱ�����ȷ��
         c.winId = bestWindow( window, wins ); //�ҳ���ѣ���̣��ķ��񴰿�/*DSA*/ToDo: ����ϸ�Ĳ���
         window[c.winId].enqueue( c ); //�¹˿ͼ����Ӧ�Ķ���
      }
      for ( Rank i = 0; i < wins; i++ ) //�ֱ���
         if ( !window[i].empty() ) //���ǿն���
            if ( -- window[i].front().time <= 0 ) //���׹˿͵ķ���ʱ������һ����λ
               window[i].dequeue(); //������ϵĹ˿ͳ��У��ɺ�̹˿ͽ���
      /*DSA*/displayProgress( window, wins, now ); //��ʾ��ǰ�������ڣ��������
      /*DSA*/delay > 0 ? //��������ָ����ʱ����Ϊ����
      /*DSA*/  _sleep( delay ) : //������Ӧ���ӳ�
      /*DSA*/  getchar(); //�������ֶ���ʽ������ʾ
   } //for
   delete [] window; //�ͷ����ж��У���ǰ��~List()���Զ���ն��У�
}