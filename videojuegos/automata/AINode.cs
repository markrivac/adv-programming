using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class AINode {

	private string name;
	private Dictionary<AISymbol, AINode> transitions;
	private Type behaviour;

	public string Name {
		get{
			return name;
		}
		private set{ 
			name = value;
		}
	}
	public Type Behaviour {
		get{
			return behaviour;
		}
	}

	public AINode(string name, Type behaviour){
		Name = name;
		this.behaviour = behaviour;
		transitions = new Dictionary<AISymbol, AINode> ();
	}

	public void AddTransition(AISymbol symbol, AINode node){
		transitions.Add(symbol, node);
	}

	public AINode ApplyTransition(AISymbol symbol){

		if (transitions.ContainsKey (symbol)) {
			return transitions [symbol];
		} else {
			return this;
		}
	}
}
