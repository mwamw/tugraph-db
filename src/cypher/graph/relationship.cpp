﻿/**
 * Copyright 2024 AntGroup CO., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

//
// Created by wt on 6/12/18.
//

#include "cypher/graph/relationship.h"

namespace cypher {

Relationship::Relationship() : id_(-1), derivation_(UNKNOWN) {}

Relationship::Relationship(RelpID id, const std::set<std::string> &types, NodeID lhs, NodeID rhs,
                           parser::LinkDirection direction, const std::string &alias,
                           Derivation derivation, bool no_duplicate_edge)
    : id_(id),
      types_(types),
      lhs_(lhs),
      rhs_(rhs),
      alias_(alias),
      direction_(direction),
      derivation_(derivation),
      no_duplicate_edge_(no_duplicate_edge) {}

Relationship::Relationship(RelpID id, const std::set<std::string> &types, NodeID src, NodeID dst,
                           parser::LinkDirection direction, const std::string &alias, int min_hop,
                           int max_hop, Derivation derivation, bool no_duplicate_edge)
    : id_(id),
      types_(types),
      lhs_(src),
      rhs_(dst),
      alias_(alias),
      direction_(direction),
      derivation_(derivation),
      min_hop_(min_hop),
      max_hop_(max_hop),
      no_duplicate_edge_(no_duplicate_edge) {
    its_.resize(max_hop_ < 0 ? 0 : max_hop_);
}

RelpID Relationship::ID() const { return id_; }

const std::set<std::string> &Relationship::Types() const { return types_; }

NodeID Relationship::Src() const {
    switch (direction_) {
    case parser::LinkDirection::LEFT_TO_RIGHT:
        return lhs_;
    case parser::LinkDirection::RIGHT_TO_LEFT:
        return rhs_;
    default:
        throw lgraph::CypherException("Failed to get src node.");
    }
}

NodeID Relationship::Dst() const {
    switch (direction_) {
    case parser::LinkDirection::LEFT_TO_RIGHT:
        return rhs_;
    case parser::LinkDirection::RIGHT_TO_LEFT:
        return lhs_;
    default:
        throw lgraph::CypherException("Failed to get dst node.");
    }
}

const std::string &Relationship::Alias() const { return alias_; }

lgraph::EIter *Relationship::ItRef() { return &it_; }

std::vector<lgraph::EIter> &Relationship::ItsRef() { return its_; }

bool Relationship::Empty() const { return (id_ < 0); }

bool Relationship::Undirected() const {
    return direction_ == parser::LinkDirection::DIR_NOT_SPECIFIED;
}

bool Relationship::VarLen() const { return CheckVarLen(min_hop_, max_hop_); }

int Relationship::MinHop() const { return min_hop_; }

int Relationship::MaxHop() const { return max_hop_; }

bool Relationship::CheckVarLen(int min_hop, int max_hop) {
    return min_hop >= 0 && max_hop >= min_hop;
}
}  // namespace cypher
