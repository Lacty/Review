
#pragma once
#include "../common.h"
#include "float2.h"
#include <string>
using namespace std;


class cAldFont {
public:

  // �`�悷��t�H���g��path
  cAldFont(const string&);

  // text  �`�悷�镶����
  // pos   �`�悷��ʒu
  // time  �������������鎞��(���l���������قǒx��)
  // color �����̐F
  void draw(const string&, const float2&,
            const float&,  const Color&);

  // const u_int& size  �t�H���g�̃T�C�Y
  void size(const u_int&);


private:

  Font   m_font;
  string m_text;
  float2 m_pos;
  Color  m_color;
  u_int  m_size;
  float  m_characters;    // �^����ꂽ�����̐���ۑ�

  float  m_count;

  int    m_current_count; // �����_���ȕ���������ۂ̕������J�E���g
  int    m_aligned_count; // �����𐮂��邽�߂̕������J�E���g

  string m_rand_alpha;    // �p�����@�Q
  string m_rand_punct;    // �@�L���@�Q

  Random random;
};