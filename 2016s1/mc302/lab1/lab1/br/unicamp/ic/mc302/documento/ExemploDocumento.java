package br.unicamp.ic.mc302.documento;

class ExemploDocumento{ 
    static public void main(String args[ ]){ 
        
    	Documento d1, d2;
        
    	// Aloca d1
    	d1 = new Documento();
    	
    	// Cria d1
        d1.criarDocumento("Camila",181101);

        // Imprime informações sobre d1
        d1.imprimir();
        
        // Edita d1 (método não implementado)
        d1.editar();
    
        // Aloca d2
        d2 = new Documento();
        
        // Cria d2        
        d2.criarDocumento("Surita", 139095);
        
        // Imprime informações sobre d2
        d2.imprimir();
    }
}
