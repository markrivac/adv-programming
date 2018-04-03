using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//.NET
public class Pathfinding {

	// 3 algorithms

	// first two - uninformed (desinformados)
	// única garantía - regresar una ruta si existe
	// no necesariamente buena
	// no necesariamente la mejor 

	public static List<Node> Breadthwise(Node start, Node end){

		List<Node> visited = new List<Node> ();
		Queue<Node> working = new Queue<Node> ();

		visited.Add (start);
		working.Enqueue (start);
		start.historial = new List<Node> ();

		while(working.Count > 0){
			
			Node current = working.Dequeue ();

			if (current == end) {
				
				/* PENDING */
				List<Node> resultado = end.historial;
				resultado.Add (end);
				return resultado;

			} else {
			
				// si no fue este, seguir buscando
				// recorrer hijos
				for(int i = 0; i < current.children.Length; i++){

					// procesar cada hijo
					Node currentChild = current.children[i];

					if (!visited.Contains (currentChild)) {

						visited.Add (currentChild);
						working.Enqueue (currentChild);
						currentChild.historial = new List<Node> (current.historial);
						currentChild.historial.Add (current);
					}
				}
			}
		}

		return null;
	}

	public static List<Node> Depthwise(Node start, Node end){

		List<Node> visited = new List<Node> ();
		Stack<Node> working = new Stack<Node> ();

		visited.Add (start);
		working.Push (start);
		start.historial = new List<Node> ();

		while(working.Count > 0){
			
			Node current = working.Pop ();
			if (current == end) {

				List<Node> resultado = current.historial;
				resultado.Add (current);
				return resultado;
			} else {

				for(int i = 0; i < current.children.Length; i++){

					Node currentChild = current.children[i];
					if (!visited.Contains (currentChild)) {
					
						visited.Add (currentChild);
						working.Push (currentChild);
						currentChild.historial = new List<Node> (current.historial);
						currentChild.historial.Add (current);
					}
				}
			}
		}

		return null;
	}

	// informed
	// - utiliza información para su criterio de búsqueda
	// - garantía: buena ruta
	// - NO necesariamente la mejor

	public static List<Node> AStar(Node start, Node end){

		List<Node> visited = new List<Node>();
		List<Node> work = new List<Node>();

		//reset values
		start.historial = new List<Node>();
		start.g = 0;
		start.h = Vector3.Distance (start.transform.position, end.transform.position);

		visited.Add (start);
		work.Add (start);

		while (work.Count > 0) {
		
			// get current node
			Node current = work[0];
			for (int i = 1; i < work.Count; i++) {
				if (work [i].F < current.F) {
					current = work [i];
				}
			}

			Debug.Log ("CURRENT: " + current.transform.name + " " + current.F);

			work.Remove (current);

			if (current == end) {
				List<Node> resultado = new List<Node> ();
				resultado.Add (current);
				return resultado;

			} else {
			
				for(int i=0; i < current.children.Length; i++){

					Node currentChild = current.children [i];
					if (!visited.Contains (currentChild)) {

						currentChild.g = current.g + Vector3.Distance (current.transform.position, currentChild.transform.position);
						currentChild.h = Vector3.Distance (currentChild.transform.position, end.transform.position);
						currentChild.historial = new List<Node> ();
						currentChild.historial.Add (current);

						if (currentChild == end) {
							currentChild.historial.Add (currentChild);
							return currentChild.historial;
						}

						visited.Add (currentChild);
						work.Add (currentChild);
					}
					
				}
			}
				
		}

		return null;
	}
}
