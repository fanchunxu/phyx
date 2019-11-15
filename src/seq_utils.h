#ifndef _SEQ_UTILS_H_
#define _SEQ_UTILS_H_

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#include "sequence.h"

std::string guess_alignment_type (std::string& sequence);
char get_dna_from_pos (std::set<int> ins);
std::set<int> get_dna_pos (char);
std::string consensus_seq (std::vector<Sequence>&, std::string& alpha);
char single_dna_complement (char inc);
void write_phylip_alignment (std::vector<Sequence>& seqs, const bool& uppercase, std::ostream * ostr);
void write_nexus_alignment (std::vector<Sequence>& seqs, const bool& uppercase, std::ostream * ostr);
void populate_codon_list (std::vector<std::string> * codon_list);
void populate_map_codon_dict (std::map<std::string, std::string> * codon_dict);
void populate_map_codon_indices (std::map<std::string, std::vector<int> > * codon_position);
void create_vector_seq_codon_state_reconstructor (std::vector<Sequence>& origseqs,
    std::vector<Sequence>& sr_seqs, int site, std::map<std::string, std::vector<int> >& codon_pos);
bool check_binary_sequence (const std::string& seq);
std::string get_alphabet_from_sequence (const std::string& instr);

#endif /* _SEQ_UTILS_H_ */
