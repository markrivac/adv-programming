using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AISymbol  {

	private string name;

	public string Name{
		get{
			return name;
		}
	}

	public AISymbol(string name){
		this.name = name;
	}
}
