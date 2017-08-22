[%bs.raw {|require('./app.css')|}];

let vDOM = Helpers.vDOM;

let component = ReasonReact.statelessComponent "App";

let make _children => {  
  {
    ...component,
    render: fun self =>
      <div className="root">
        <Header title="Giphy"/>
        <div className="main">
          <h3>(vDOM "Welcome to Giphy")</h3>
          <h3>(vDOM "Welcome AGAIN!!!")</h3>          
          <h3>(vDOM "Write something again!!!")</h3>          
          <h3>(vDOM "Make React Great Again")</h3>       
          <p>(vDOM "Make React Great Again")</p>          
          
        </div>
        <Footer/>
      </div>
  }
};
