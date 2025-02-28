import "./product.css"

function Product({title, price}) {
    return (
        <div className="Product">
            <h3>product is {title}</h3>
            <h5>Product Price is : {price}</h5>
        </div>
    );
};
export default Product;