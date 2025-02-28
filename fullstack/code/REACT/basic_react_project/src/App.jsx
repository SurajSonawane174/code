import "./App.css"
import  Product from "./product.jsx";
import Title from "./Title.jsx";


function App() {
  return (
    // <Title></Title> 
    // <Title/>
    <div>

      <Title/>
      <Product title="phone" price={50000}/>
      <Product title="laptop" price={100000}/>
      <Product title="watch" price={3000}/>

      

    </div>
  );
}

export default App;
