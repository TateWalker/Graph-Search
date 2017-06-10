#include "Graph.hpp"


using namespace std;


Graph::Graph(){

} // default constructor

Graph::Graph(vector<list<Edge> > adjl){ // constructor from adjl = adjacency list (optional)

} 
vector<list<Edge> > Graph::buildGraph(ifstream& in){ //build a graph from the adjacency list
	/*EDGE IS MADE UP OF TWO VERTICES WHICH ARE INTS
	SO I'M JUST USING INTS*/

	vector<list<Edge> > adj_list(20); // adjacency list

	Edge connection;
	int i = 0;
	int end;
	string dummy;
	getline(in,dummy); //ignores the first line
	while(in >> end){
		if(end!=-1){
			connection.start = i;
			connection.end = end;
			adj_list[i].push_back(connection);
		}
		else{
			i++;
		}
	}
	return adj_list;
}
void Graph::displayGraph(vector<list<Edge> > adj){  //display the graph
	int i = 0;
	list<Edge>::iterator it;
	while(!adj[i].empty()){
		cout<<i<<": ";
		for(it = adj[i].begin(); it != adj[i].end(); it++){	
				cout<<(it)->end<<"     ";
		}
		cout<<endl;
		i++;
	}
}
bool Graph::partitionable(vector<list<Edge> > adj){
	vector<int> A(10);
	vector<int> B(10);
	int i = 0;
	list<Edge>::iterator it;
	while(adj[i].empty()){
		i++;
	}
	A.push_back(i);
	while(!adj[i].empty()){
		for(it = adj[i].begin(); it != adj[i].end(); it++){
			//cout<<"I: "<<i<<endl;
			if(find(A.begin(),A.end(), i) != A.end()){ //if origin is already in A, put destinations in B
				//cout<<"THIS: "<<(it)->end<<endl;
				if(find(A.begin(),A.end(), (it)->end) != A.end() && (it)->end != 0) { //if in B also, return false
					return false;
				}
				if(find(B.begin(), B.end(), (it)->end) == B.end()) { //prevent duplicates
					B.push_back((it)->end);
					//cout<<"Origin: "<<i<<endl;
					//cout<<"I just pushed into B: "<<(it)->end<<endl;
				}
			}
			else if(find(B.begin(),B.end(), i) != B.end()){ //if origin is already in B, put destinations in A
				if(find(B.begin(),B.end(), (it)->end) != B.end() && (it)->end != 0) { //if in A also, return false
					//cout<<"STOP\n";
					return false;
				}
				if(find(A.begin(), A.end(), (it)->end) == A.end()) { //prevent duplicates
					A.push_back((it)->end);
					//cout<<"Origin: "<<i<<endl;
					//cout<<"I just pushed into A: "<<(it)->end<<endl;
				}
			}
		}
		i++;
	}
	i = 0;
	while(adj[i].empty()){
		i++;
	}
	while(!adj[i].empty()){
		for(it = adj[i].begin(); it != adj[i].end(); it++){
			//cout<<"I: "<<i<<endl;
			if(find(A.begin(),A.end(), i) != A.end()){ //if origin is already in A, put destinations in B
				//cout<<"THIS: "<<(it)->end<<endl;
				if(find(A.begin(),A.end(), (it)->end) != A.end() && (it)->end != 0) { //if in B also, return false
					return false;
				}
				if(find(B.begin(), B.end(), (it)->end) == B.end()) { //prevent duplicates
					B.push_back((it)->end);
					//cout<<"Origin: "<<i<<endl;
					//cout<<"I just pushed into B: "<<(it)->end<<endl;
				}
			}
			else if(find(B.begin(),B.end(), i) != B.end()){ //if origin is already in B, put destinations in A
				if(find(B.begin(),B.end(), (it)->end) != B.end() && (it)->end != 0) { //if in A also, return false
					//cout<<"STOP\n";
					return false;
				}
				if(find(A.begin(), A.end(), (it)->end) == A.end()) { //prevent duplicates
					A.push_back((it)->end);
					//cout<<"Origin: "<<i<<endl;
					//cout<<"I just pushed into A: "<<(it)->end<<endl;
				}
			}
		}
		i++;
	}
	/*Prints out the two groups*/
	cout<<"\nGroup 1:"<<endl;
	int z = 0;
	cout<< z;
	while(A[z] == 0){
		z++;
	}
	for (z;z<A.size();z++){
			cout<<"\t"<<A[z];
	}
	cout<<"\n\nGroup 2:"<<endl;
	z = 0;
	while(B[z] == 0){
		z++;
	}
	for (z;z<B.size();z++){
		if(B[z] != 0){	
			cout<<B[z]<<"\t";
		}
	}
	cout<<"\n\n";
	return true;
}


void Graph::bfs(vector<list<Edge> > adj, int source, int destination) {
	vector<int> verts(20); //all possible vertice values
	list<Edge>::iterator it;
	int i = 0;
	while(!adj[i].empty()){
		verts.push_back(i);
		i++;
	}
	if(source == destination){
		cout<<"Source is the same as destination\n";
	}
	else if(find(verts.begin(), verts.end(), source) == verts.end() || (find(verts.begin(), verts.end(), destination) == verts.end())) { 
		cout<<"One of those values doesn't exist in this graph, please try again from the above values\n";
	}
	else{
	int V = adj.size();
	bool *visited = new bool[V];
	int rSource = source;
	for(int i = 0; i<V; i++){
		visited[i] = false;
	}
		list<int> queue;
		list<Edge> parents;
		visited[source] = true;
		queue.push_back(source);
		Edge temp;
		//list<Edge>::iterator it;
		list<int>::iterator iter;
		bool test = true;
		while(test){//source != destination){
			source = queue.front();
			//cout << source <<" ";
			queue.pop_front();

			for(it = adj[source].begin(); it != adj[source].end(); it++){
				if(!visited[it->end]){
					visited[it->end] = true;
					temp.start = it->start;
					temp.end = it->end;
					parents.push_back(temp);
					queue.push_back(it->end);
				}
			}
			iter = find(queue.begin(), queue.end(), destination);
			if(iter != queue.end()) test = false;
		}
		list<Edge>::iterator itr;
		// for(itr = parents.begin(); itr != parents.end(); itr++){	
		// 		cout<<"Start: "<<(itr)->start<<" End: "<<(itr)->end<<endl;
		// }
		itr = parents.end();
		itr--;

		int tester = 0;
		stack<int> shortest;
		shortest.push(destination);
		tester = itr->start;
		while((itr)->start != rSource){
			shortest.push(tester);
			itr = parents.begin();
			while(itr->end != tester){
				itr++;
			}
			tester = itr->start;

		}
		shortest.push(rSource);
		cout<<"Shortest path from "<<rSource<<" to "<<destination<< " is:\n"<<shortest.top();
		shortest.pop();
		while(!shortest.empty()){
			cout<<" -> "<<shortest.top();
			shortest.pop();
		}
		cout<<endl;
}
}
