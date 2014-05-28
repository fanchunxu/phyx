/*
 * tree_reader.h
 *
 *  Created on: Nov 24, 2009
 *      Author: smitty
 */

#ifndef _TREE_READER_H_
#define _TREE_READER_H_

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

#include "node.h"
#include "tree.h"

class TreeReader{
public:
	TreeReader();
	Tree * readTree(string trees);
};

Tree * read_tree_string(string trees);
int test_tree_filetype(string filen);
int test_tree_filetype_stream(istream & stri, string & retstring);
bool get_nexus_translation_table(istream & stri, map<string,string> * trans,vector<string> * retstrings);
Tree * read_next_tree_from_stream_nexus(istream & stri, string & retstring,bool ttexists, map<string,string> * trans,bool * going);
Tree * read_next_tree_from_stream_newick(istream & stri, string & retstring, bool * going);

#endif /* _TREE_READER_H_ */
